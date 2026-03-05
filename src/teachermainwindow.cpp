#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"
#include "authcontroller.h"
#include "teacherdao.h"
#include "teacherprofiledialog.h"
#include "gradeeditdialog.h"
#include "gradestatsdialog.h"
#include "gradedao.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QButtonGroup>

TeacherMainWindow::TeacherMainWindow(const User& user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherMainWindow),
    m_currentUser(user)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 - 教师");
    
    TeacherDAO teacherDAO;
    auto teacherOpt = teacherDAO.findByUserId(user.id());
    if (teacherOpt.has_value()) {
        m_teacherId = teacherOpt->id();
        m_currentTeacher = teacherOpt.value();
    }
    
    QButtonGroup* navGroup = new QButtonGroup(this);
    navGroup->addButton(ui->navProfileButton, 0);
    navGroup->addButton(ui->navCoursesButton, 1);
    navGroup->setExclusive(true);
    
    connect(navGroup, QOverload<int>::of(&QButtonGroup::idClicked), this, [this](int id) {
        updateNavButtons(id);
        switch (id) {
            case 0: onNavProfileClicked(); break;
            case 1: onNavCoursesClicked(); break;
        }
    });
    
    connect(ui->logoutButton, &QPushButton::clicked, this, &TeacherMainWindow::onLogoutClicked);
    connect(ui->editProfileButton, &QPushButton::clicked, this, &TeacherMainWindow::onEditProfileClicked);
    
    connect(ui->courseTable, &QTableWidget::cellDoubleClicked, this, &TeacherMainWindow::onCourseDoubleClicked);
    connect(ui->editGradeButton, &QPushButton::clicked, this, &TeacherMainWindow::onEditGradeClicked);
    connect(ui->viewStatsButton, &QPushButton::clicked, this, &TeacherMainWindow::onViewStatsClicked);
    connect(ui->refreshCoursesButton, &QPushButton::clicked, this, &TeacherMainWindow::onNavCoursesClicked);
    connect(ui->refreshCourseStudentsButton, &QPushButton::clicked, this, [this]() {
        if (m_currentCourseId > 0) {
            loadCourseStudents(m_currentCourseId);
        }
    });
    connect(ui->backToCoursesButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->coursesPage);
        updateNavButtons(1);
        ui->navCoursesButton->setChecked(true);
        m_currentCourseId = 0;
    });
    
    QString tableStyle = "QTableWidget::item:selected { background-color: #4a90d9; color: white; }";
    
    QFont tableFont;
    tableFont.setPointSize(12);
    
    ui->courseTable->setFont(tableFont);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseTable->setStyleSheet(tableStyle);
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->courseTable->verticalHeader()->setDefaultSectionSize(35);
    
    ui->courseStudentTable->setFont(tableFont);
    ui->courseStudentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseStudentTable->setStyleSheet(tableStyle);
    ui->courseStudentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseStudentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->courseStudentTable->verticalHeader()->setDefaultSectionSize(35);
    
    onNavProfileClicked();
}

TeacherMainWindow::~TeacherMainWindow()
{
    delete ui;
}

void TeacherMainWindow::updateNavButtons(int index)
{
    ui->navProfileButton->setChecked(index == 0);
    ui->navCoursesButton->setChecked(index == 1);
}

void TeacherMainWindow::onNavProfileClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
    loadProfile();
}

void TeacherMainWindow::onNavCoursesClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->coursesPage);
    loadMyCourses();
}

void TeacherMainWindow::onLogoutClicked()
{
    AuthController::instance().logout();
    close();
}

void TeacherMainWindow::onEditProfileClicked()
{
    TeacherProfileDialog dialog(this);
    dialog.setTeacher(m_currentTeacher);
    
    if (dialog.exec() == QDialog::Accepted) {
        Teacher updatedTeacher = dialog.getTeacher();
        
        if (m_teacherController.updateTeacher(updatedTeacher)) {
            m_currentTeacher = updatedTeacher;
            QMessageBox::information(this, "成功", "个人信息更新成功");
            loadProfile();
        } else {
            QMessageBox::warning(this, "失败", "个人信息更新失败");
        }
    }
}

void TeacherMainWindow::onCourseDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    
    if (row < 0) return;
    
    int courseId = ui->courseTable->item(row, 0)->data(Qt::UserRole).toInt();
    if (courseId > 0) {
        m_currentCourseId = courseId;
        loadCourseStudents(courseId);
        ui->stackedWidget->setCurrentWidget(ui->courseStudentsPage);
    }
}

void TeacherMainWindow::onEditGradeClicked()
{
    int row = ui->courseStudentTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要修改成绩的学生");
        return;
    }
    
    QString studentNo = ui->courseStudentTable->item(row, 0)->text();
    QString studentName = ui->courseStudentTable->item(row, 1)->text();
    int currentGrade = ui->courseStudentTable->item(row, 6)->text().toInt();
    
    GradeEditDialog dialog(this);
    dialog.setStudentInfo(studentNo, studentName);
    dialog.setGrade(currentGrade);
    
    if (dialog.exec() == QDialog::Accepted) {
        int newGrade = dialog.getGrade();
        
        GradeDAO gradeDAO;
        QVector<Grade> allGrades = gradeDAO.findAll();
        
        int gradeId = -1;
        int studentId = -1;
        
        QVector<Student> allStudents = m_studentController.getAllStudents();
        for (const Student& s : allStudents) {
            if (s.studentNo() == studentNo) {
                studentId = s.id();
                break;
            }
        }
        
        for (const Grade& g : allGrades) {
            if (g.courseId() == m_currentCourseId && g.studentId() == studentId) {
                gradeId = g.id();
                break;
            }
        }
        
        if (gradeId > 0) {
            Grade grade;
            grade.setId(gradeId);
            grade.setCourseId(m_currentCourseId);
            grade.setStudentId(studentId);
            grade.setGrade(newGrade);
            
            for (const Grade& g : allGrades) {
                if (g.id() == gradeId) {
                    grade.setSemester(g.semester());
                    grade.setExamType(g.examType());
                    break;
                }
            }
            
            if (m_gradeController.updateGrade(grade)) {
                QMessageBox::information(this, "成功", "成绩修改成功");
                loadCourseStudents(m_currentCourseId);
            } else {
                QMessageBox::warning(this, "失败", "成绩修改失败");
            }
        } else {
            QMessageBox::warning(this, "错误", "未找到成绩记录");
        }
    }
}

void TeacherMainWindow::onViewStatsClicked()
{
    if (m_currentGrades.isEmpty()) {
        QMessageBox::information(this, "提示", "当前课程暂无成绩数据");
        return;
    }
    
    GradeStatsDialog dialog(this);
    dialog.setCourseName(m_currentCourseName);
    dialog.setGrades(m_currentGrades);
    dialog.exec();
}

void TeacherMainWindow::loadProfile()
{
    TeacherDAO teacherDAO;
    auto teacherOpt = teacherDAO.findByUserId(m_currentUser.id());
    
    if (teacherOpt.has_value()) {
        Teacher t = teacherOpt.value();
        m_teacherId = t.id();
        m_currentTeacher = t;
        
        ui->teacherNoLabel->setText(t.teacherNo());
        ui->nameLabel->setText(t.name());
        ui->genderLabel->setText(t.gender());
        ui->ageLabel->setText(QString::number(t.age()));
        ui->departmentLabel->setText(t.department());
        ui->titleLabelValue->setText(t.title());
        ui->phoneLabel->setText(t.phone());
        ui->emailLabel->setText(t.email());
        
        statusBar()->showMessage(QString("欢迎，%1 老师").arg(t.name()));
    } else {
        ui->nameLabel->setText(m_currentUser.username());
        statusBar()->showMessage(QString("当前用户: %1").arg(m_currentUser.username()));
    }
}

void TeacherMainWindow::loadMyCourses()
{
    QVector<Course> courses = m_courseController.getCoursesByTeacher(m_teacherId);
    
    ui->courseTable->clear();
    ui->courseTable->setRowCount(courses.size());
    ui->courseTable->setColumnCount(4);
    ui->courseTable->setHorizontalHeaderLabels({"课程号", "课程名", "学分", "学时"});
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    
    for (int i = 0; i < courses.size(); ++i) {
        const Course& c = courses[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(c.courseNo());
        item0->setData(Qt::UserRole, c.id());
        ui->courseTable->setItem(i, 0, item0);
        ui->courseTable->setItem(i, 1, new QTableWidgetItem(c.courseName()));
        ui->courseTable->setItem(i, 2, new QTableWidgetItem(QString::number(c.credit())));
        ui->courseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.hours())));
    }
    
    statusBar()->showMessage(QString("共 %1 门课程 (双击查看课程学生)").arg(courses.size()));
}

void TeacherMainWindow::loadCourseStudents(int courseId)
{
    QVector<Grade> allGrades = m_gradeController.getAllGrades();
    QVector<Student> allStudents = m_studentController.getAllStudents();
    
    QMap<int, Student> studentMap;
    for (const Student& s : allStudents) {
        studentMap[s.id()] = s;
    }
    
    m_currentCourseName.clear();
    QVector<Course> courses = m_courseController.getCoursesByTeacher(m_teacherId);
    for (const Course& c : courses) {
        if (c.id() == courseId) {
            m_currentCourseName = c.courseName();
            break;
        }
    }
    
    ui->courseStudentsTitleLabel->setText(QString("课程【%1】学生列表").arg(m_currentCourseName));
    
    QVector<Student> courseStudents;
    QVector<int> studentIds;
    m_currentGrades.clear();
    QMap<int, int> studentGradeMap;
    
    for (const Grade& g : allGrades) {
        if (g.courseId() == courseId) {
            studentGradeMap[g.studentId()] = g.grade();
            m_currentGrades.append(g.grade());
            
            if (!studentIds.contains(g.studentId()) && studentMap.contains(g.studentId())) {
                studentIds.append(g.studentId());
                courseStudents.append(studentMap[g.studentId()]);
            }
        }
    }
    
    ui->courseStudentTable->clear();
    ui->courseStudentTable->setRowCount(courseStudents.size());
    ui->courseStudentTable->setColumnCount(7);
    ui->courseStudentTable->setHorizontalHeaderLabels({"学号", "姓名", "性别", "年龄", "院系", "班级", "成绩"});
    ui->courseStudentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    
    for (int i = 0; i < courseStudents.size(); ++i) {
        const Student& s = courseStudents[i];
        ui->courseStudentTable->setItem(i, 0, new QTableWidgetItem(s.studentNo()));
        ui->courseStudentTable->setItem(i, 1, new QTableWidgetItem(s.name()));
        ui->courseStudentTable->setItem(i, 2, new QTableWidgetItem(s.gender()));
        ui->courseStudentTable->setItem(i, 3, new QTableWidgetItem(QString::number(s.age())));
        ui->courseStudentTable->setItem(i, 4, new QTableWidgetItem(s.department()));
        ui->courseStudentTable->setItem(i, 5, new QTableWidgetItem(s.className()));
        ui->courseStudentTable->setItem(i, 6, new QTableWidgetItem(QString::number(studentGradeMap.value(s.id(), 0))));
    }
    
    statusBar()->showMessage(QString("该课程共 %1 名学生，选中后可修改成绩").arg(courseStudents.size()));
}
