#include "teachermainwindow.h"
#include "ui_teachermainwindow.h"
#include "teacherprofiledialog.h"
#include "gradeeditdialog.h"
#include "gradestatsdialog.h"
#include "teacherdao.h"
#include "studentdao.h"
#include "gradedao.h"
#include <QMessageBox>
#include <QHeaderView>

TeacherMainWindow::TeacherMainWindow(const User& user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherMainWindow),
    m_currentUser(user)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 - 教师");

    connect(ui->navProfileButton, &QPushButton::clicked, this, &TeacherMainWindow::onNavProfileClicked);
    connect(ui->navCoursesButton, &QPushButton::clicked, this, &TeacherMainWindow::onNavCoursesClicked);
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

    // 连接表格悬停信号以显示tooltip
    connect(ui->courseTable, &QTableWidget::itemEntered, this, &TeacherMainWindow::onCourseTableItemEntered);
    connect(ui->courseStudentTable, &QTableWidget::itemEntered, this, &TeacherMainWindow::onCourseStudentTableItemEntered);

    // 启用鼠标追踪
    ui->courseTable->setMouseTracking(true);
    ui->courseStudentTable->setMouseTracking(true);

    QString tableStyle = "QTableWidget::item:selected { background-color: #4a90d9; color: white; }";

    QFont tableFont;
    tableFont.setPointSize(12);

    ui->courseTable->setFont(tableFont);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseTable->setStyleSheet(tableStyle);
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->courseTable->verticalHeader()->setDefaultSectionSize(35);
    ui->courseTable->verticalHeader()->setMinimumSectionSize(35);
    ui->courseTable->verticalHeader()->setFixedWidth(50);

    ui->courseStudentTable->setFont(tableFont);
    ui->courseStudentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseStudentTable->setStyleSheet(tableStyle);
    ui->courseStudentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseStudentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->courseStudentTable->verticalHeader()->setDefaultSectionSize(35);
    ui->courseStudentTable->verticalHeader()->setMinimumSectionSize(35);
    ui->courseStudentTable->verticalHeader()->setFixedWidth(50);

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
    updateNavButtons(0);
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
    loadProfile();
}

void TeacherMainWindow::onNavCoursesClicked()
{
    updateNavButtons(1);
    ui->stackedWidget->setCurrentWidget(ui->coursesPage);
    loadMyCourses();
}

void TeacherMainWindow::onLogoutClicked()
{
    if (QMessageBox::question(this, "确认", "确定要退出登录吗？") == QMessageBox::Yes) {
        close();
        emit logoutRequested();
    }
}

void TeacherMainWindow::onEditProfileClicked()
{
    TeacherProfileDialog dialog(this);
    dialog.setTeacher(m_currentTeacher);

    if (dialog.exec() == QDialog::Accepted) {
        Teacher updatedTeacher = dialog.getTeacher();
        updatedTeacher.setId(m_currentTeacher.id());
        updatedTeacher.setUserId(m_currentTeacher.userId());
        updatedTeacher.setTeacherNo(m_currentTeacher.teacherNo());

        if (m_teacherController.updateTeacher(updatedTeacher)) {
            QMessageBox::information(this, "成功", "个人信息更新成功");
            loadProfile();
        } else {
            QMessageBox::warning(this, "失败", "更新失败");
        }
    }
}

void TeacherMainWindow::onCourseDoubleClicked(int row, int column)
{
    Q_UNUSED(column)

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
    int currentGrade = ui->courseStudentTable->item(row, 4)->text().toInt();

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

            if (m_gradeController.updateGrade(grade)) {
                QMessageBox::information(this, "成功", "成绩修改成功");
                loadCourseStudents(m_currentCourseId);
            } else {
                QMessageBox::warning(this, "失败", "成绩修改失败");
            }
        } else {
            QMessageBox::warning(this, "失败", "找不到该学生的成绩记录");
        }
    }
}

void TeacherMainWindow::onViewStatsClicked()
{
    if (m_currentGrades.isEmpty()) {
        QMessageBox::information(this, "提示", "当前课程没有学生成绩数据");
        return;
    }

    GradeStatsDialog dialog(this);
    dialog.setGrades(m_currentGrades);
    dialog.setCourseName(m_currentCourseName);
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
        ui->coursesLabel->setText(t.coursesString().isEmpty() ? "暂无授课" : t.coursesString());

        statusBar()->showMessage(QString("欢迎，%1 老师").arg(t.name()));
    } else {
        ui->nameLabel->setText(m_currentUser.username());
        ui->coursesLabel->setText("-");
        statusBar()->showMessage(QString("当前用户: %1").arg(m_currentUser.username()));
    }
}

void TeacherMainWindow::loadMyCourses()
{
    // 只显示当前教师教授的课程
    QVector<Course> courses;
    if (m_teacherId > 0) {
        courses = m_courseController.getCoursesByTeacher(m_teacherId);
    }

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

    if (courses.isEmpty()) {
        statusBar()->showMessage("您暂时没有教授的课程");
    } else {
        statusBar()->showMessage(QString("共 %1 门课程 (双击查看课程学生)").arg(courses.size()));
    }
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
    QVector<Course> courses = m_courseController.getAllCourses();
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
    ui->courseStudentTable->setColumnCount(5);
    ui->courseStudentTable->setHorizontalHeaderLabels({"学号", "姓名", "班级", "专业", "成绩"});
    ui->courseStudentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < courseStudents.size(); ++i) {
        const Student& s = courseStudents[i];
        ui->courseStudentTable->setItem(i, 0, new QTableWidgetItem(s.studentNo()));
        ui->courseStudentTable->setItem(i, 1, new QTableWidgetItem(s.name()));
        ui->courseStudentTable->setItem(i, 2, new QTableWidgetItem(s.className()));
        ui->courseStudentTable->setItem(i, 3, new QTableWidgetItem(s.major()));
        ui->courseStudentTable->setItem(i, 4, new QTableWidgetItem(QString::number(studentGradeMap.value(s.id(), 0))));
    }

    statusBar()->showMessage(QString("该课程共 %1 名学生，选中后可修改成绩").arg(courseStudents.size()));
}

// 鼠标悬停显示单元格全文
void TeacherMainWindow::onCourseTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void TeacherMainWindow::onCourseStudentTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}
