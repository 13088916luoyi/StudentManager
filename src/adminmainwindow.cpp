#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "authcontroller.h"
#include "studentdialog.h"
#include "teacherdialog.h"
#include "coursedialog.h"
#include "gradedialog.h"
#include "accountdialog.h"
#include "userdao.h"
#include "passwordhasher.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QButtonGroup>
#include <QUuid>

AdminMainWindow::AdminMainWindow(const User& user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow),
    m_currentUser(user)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 - 管理员");
    statusBar()->showMessage(QString("当前用户: %1 (管理员)").arg(user.username()));

    QButtonGroup* navGroup = new QButtonGroup(this);
    navGroup->addButton(ui->navStudentButton, 0);
    navGroup->addButton(ui->navTeacherButton, 1);
    navGroup->addButton(ui->navCourseButton, 2);
    navGroup->addButton(ui->navGradeButton, 3);
    navGroup->addButton(ui->navAccountButton, 4);
    navGroup->setExclusive(true);

    connect(ui->navStudentButton, &QPushButton::clicked, this, &AdminMainWindow::onNavStudentClicked);
    connect(ui->navTeacherButton, &QPushButton::clicked, this, &AdminMainWindow::onNavTeacherClicked);
    connect(ui->navCourseButton, &QPushButton::clicked, this, &AdminMainWindow::onNavCourseClicked);
    connect(ui->navGradeButton, &QPushButton::clicked, this, &AdminMainWindow::onNavGradeClicked);
    connect(ui->navAccountButton, &QPushButton::clicked, this, &AdminMainWindow::onNavAccountClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &AdminMainWindow::onLogoutClicked);

    connect(ui->addStudentButton, &QPushButton::clicked, this, &AdminMainWindow::onAddStudentClicked);
    connect(ui->editStudentButton, &QPushButton::clicked, this, &AdminMainWindow::onEditStudentClicked);
    connect(ui->deleteStudentButton, &QPushButton::clicked, this, &AdminMainWindow::onDeleteStudentClicked);
    connect(ui->refreshStudentButton, &QPushButton::clicked, this, &AdminMainWindow::onRefreshStudentsClicked);
    connect(ui->studentSearchEdit, &QLineEdit::textChanged, this, &AdminMainWindow::onSearchStudentChanged);

    connect(ui->addTeacherButton, &QPushButton::clicked, this, &AdminMainWindow::onAddTeacherClicked);
    connect(ui->editTeacherButton, &QPushButton::clicked, this, &AdminMainWindow::onEditTeacherClicked);
    connect(ui->deleteTeacherButton, &QPushButton::clicked, this, &AdminMainWindow::onDeleteTeacherClicked);
    connect(ui->refreshTeacherButton, &QPushButton::clicked, this, &AdminMainWindow::onRefreshTeachersClicked);
    connect(ui->teacherSearchEdit, &QLineEdit::textChanged, this, &AdminMainWindow::onSearchTeacherChanged);

    connect(ui->addCourseButton, &QPushButton::clicked, this, &AdminMainWindow::onAddCourseClicked);
    connect(ui->editCourseButton, &QPushButton::clicked, this, &AdminMainWindow::onEditCourseClicked);
    connect(ui->deleteCourseButton, &QPushButton::clicked, this, &AdminMainWindow::onDeleteCourseClicked);
    connect(ui->refreshCourseButton, &QPushButton::clicked, this, &AdminMainWindow::onRefreshCoursesClicked);
    connect(ui->courseSearchEdit, &QLineEdit::textChanged, this, &AdminMainWindow::onSearchCourseChanged);

    connect(ui->addGradeButton, &QPushButton::clicked, this, &AdminMainWindow::onAddGradeClicked);
    connect(ui->editGradeButton, &QPushButton::clicked, this, &AdminMainWindow::onEditGradeClicked);
    connect(ui->deleteGradeButton, &QPushButton::clicked, this, &AdminMainWindow::onDeleteGradeClicked);
    connect(ui->refreshGradeButton, &QPushButton::clicked, this, &AdminMainWindow::onRefreshGradesClicked);
    connect(ui->gradeSearchEdit, &QLineEdit::textChanged, this, &AdminMainWindow::onSearchGradeChanged);

    // 连接表格单元格悬停信号
    connect(ui->studentTable, &QTableWidget::itemEntered, this, &AdminMainWindow::onStudentTableItemEntered);
    connect(ui->teacherTable, &QTableWidget::itemEntered, this, &AdminMainWindow::onTeacherTableItemEntered);
    connect(ui->courseTable, &QTableWidget::itemEntered, this, &AdminMainWindow::onCourseTableItemEntered);
    connect(ui->gradeTable, &QTableWidget::itemEntered, this, &AdminMainWindow::onGradeTableItemEntered);
    connect(ui->accountTable, &QTableWidget::itemEntered, this, &AdminMainWindow::onAccountTableItemEntered);

    // 启用鼠标追踪以接收悬停事件
    ui->studentTable->setMouseTracking(true);
    ui->teacherTable->setMouseTracking(true);
    ui->courseTable->setMouseTracking(true);
    ui->gradeTable->setMouseTracking(true);
    ui->accountTable->setMouseTracking(true);

    // 账号管理按钮连接
    connect(ui->addAccountButton, &QPushButton::clicked, this, &AdminMainWindow::onAddAccountClicked);
    connect(ui->editAccountButton, &QPushButton::clicked, this, &AdminMainWindow::onEditAccountClicked);
    connect(ui->deleteAccountButton, &QPushButton::clicked, this, &AdminMainWindow::onDeleteAccountClicked);
    connect(ui->refreshAccountButton, &QPushButton::clicked, this, &AdminMainWindow::onRefreshAccountsClicked);
    connect(ui->accountSearchEdit, &QLineEdit::textChanged, this, &AdminMainWindow::onSearchAccountChanged);

    setupStudentPage();
    setupTeacherPage();
    setupCoursePage();
    setupGradePage();
    setupAccountPage();

    onNavStudentClicked();
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::updateNavButtons(int index)
{
    ui->navStudentButton->setChecked(index == 0);
    ui->navTeacherButton->setChecked(index == 1);
    ui->navCourseButton->setChecked(index == 2);
    ui->navGradeButton->setChecked(index == 3);
    ui->navAccountButton->setChecked(index == 4);
}

void AdminMainWindow::setupStudentPage()
{
    ui->studentTable->setColumnCount(5);
    ui->studentTable->setHorizontalHeaderLabels({"ID", "学号", "姓名", "班级", "专业"});
    ui->studentTable->setColumnHidden(0, true);
    ui->studentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->studentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->studentTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->studentTable->verticalHeader()->setDefaultSectionSize(30);
    ui->studentTable->verticalHeader()->setFixedWidth(50);
}

void AdminMainWindow::setupTeacherPage()
{
    ui->teacherTable->setColumnCount(4);
    ui->teacherTable->setHorizontalHeaderLabels({"ID", "工号", "姓名", "教授课程"});
    ui->teacherTable->setColumnHidden(0, true);
    ui->teacherTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->teacherTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->teacherTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->teacherTable->verticalHeader()->setDefaultSectionSize(30);
    ui->teacherTable->verticalHeader()->setFixedWidth(50);
}

void AdminMainWindow::setupCoursePage()
{
    ui->courseTable->setColumnCount(6);
    ui->courseTable->setHorizontalHeaderLabels({"ID", "课程号", "课程名", "学分", "学时", "课程类别"});
    ui->courseTable->setColumnHidden(0, true);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->courseTable->verticalHeader()->setDefaultSectionSize(30);
    ui->courseTable->verticalHeader()->setFixedWidth(50);
}

void AdminMainWindow::setupGradePage()
{
    ui->gradeTable->setColumnCount(6);
    ui->gradeTable->setHorizontalHeaderLabels({"ID", "学生姓名", "学生学号", "课程名", "课程号", "成绩"});
    ui->gradeTable->setColumnHidden(0, true);
    ui->gradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->gradeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->gradeTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->gradeTable->verticalHeader()->setDefaultSectionSize(30);
    ui->gradeTable->verticalHeader()->setFixedWidth(50);
}

void AdminMainWindow::setupAccountPage()
{
    ui->accountTable->setColumnCount(5);
    ui->accountTable->setHorizontalHeaderLabels({"ID", "用户名", "账号", "密码", "角色"});
    ui->accountTable->setColumnHidden(0, true);
    ui->accountTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->accountTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->accountTable->verticalHeader()->setDefaultSectionSize(30);
    ui->accountTable->verticalHeader()->setFixedWidth(50);
}

void AdminMainWindow::onNavStudentClicked()
{
    updateNavButtons(0);
    ui->stackedWidget->setCurrentWidget(ui->studentPage);
    loadStudents();
}

void AdminMainWindow::onNavTeacherClicked()
{
    updateNavButtons(1);
    ui->stackedWidget->setCurrentWidget(ui->teacherPage);
    loadTeachers();
}

void AdminMainWindow::onNavCourseClicked()
{
    updateNavButtons(2);
    ui->stackedWidget->setCurrentWidget(ui->coursePage);
    loadCourses();
}

void AdminMainWindow::onNavGradeClicked()
{
    updateNavButtons(3);
    ui->stackedWidget->setCurrentWidget(ui->gradePage);
    loadGrades();
}

void AdminMainWindow::onNavAccountClicked()
{
    updateNavButtons(4);
    ui->stackedWidget->setCurrentWidget(ui->accountPage);
    loadAccounts();
}

void AdminMainWindow::onLogoutClicked()
{
    AuthController::instance().logout();
    close();
}

void AdminMainWindow::onAddStudentClicked()
{
    StudentDialog dialog(this);
    dialog.setEditMode(false);
    
    if (dialog.exec() == QDialog::Accepted) {
        Student student = dialog.getStudent();
        
        if (student.studentNo().isEmpty() || student.name().isEmpty()) {
            QMessageBox::warning(this, "提示", "学号和姓名不能为空");
            return;
        }
        
        if (m_studentController.addStudent(student)) {
            QMessageBox::information(this, "成功", "添加学生成功");
            loadStudents();
        } else {
            QMessageBox::warning(this, "失败", "添加学生失败，学号可能已存在");
        }
    }
}

void AdminMainWindow::onEditStudentClicked()
{
    int row = ui->studentTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要编辑的学生");
        return;
    }

    int id = ui->studentTable->item(row, 0)->text().toInt();
    auto studentOpt = m_studentController.getStudentById(id);
    
    if (!studentOpt.has_value()) {
        QMessageBox::warning(this, "错误", "找不到该学生");
        return;
    }

    StudentDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setStudent(studentOpt.value());
    
    if (dialog.exec() == QDialog::Accepted) {
        Student student = dialog.getStudent();
        student.setId(id);
        
        if (m_studentController.updateStudent(student)) {
            QMessageBox::information(this, "成功", "更新学生成功");
            loadStudents();
        } else {
            QMessageBox::warning(this, "失败", "更新学生失败");
        }
    }
}

void AdminMainWindow::onDeleteStudentClicked()
{
    int row = ui->studentTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要删除的学生");
        return;
    }

    QString name = ui->studentTable->item(row, 2)->text();
    int id = ui->studentTable->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "确认", 
        QString("确定要删除学生 \"%1\" 吗？").arg(name),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (m_studentController.deleteStudent(id)) {
            QMessageBox::information(this, "成功", "删除学生成功");
            loadStudents();
        } else {
            QMessageBox::warning(this, "失败", "删除学生失败");
        }
    }
}

void AdminMainWindow::onRefreshStudentsClicked()
{
    loadStudents();
}

void AdminMainWindow::onSearchStudentChanged(const QString& text)
{
    if (text.isEmpty()) {
        loadStudents();
    } else {
        QVector<Student> students = m_studentController.searchStudents(text);

        ui->studentTable->setRowCount(students.size());
        for (int i = 0; i < students.size(); ++i) {
            const Student& s = students[i];
            ui->studentTable->setItem(i, 0, new QTableWidgetItem(QString::number(s.id())));
            ui->studentTable->setItem(i, 1, new QTableWidgetItem(s.studentNo()));
            ui->studentTable->setItem(i, 2, new QTableWidgetItem(s.name()));
            ui->studentTable->setItem(i, 3, new QTableWidgetItem(s.className()));
            ui->studentTable->setItem(i, 4, new QTableWidgetItem(s.major()));
        }
    }
}

void AdminMainWindow::onSearchTeacherChanged(const QString& text)
{
    if (text.isEmpty()) {
        loadTeachers();
    } else {
        QVector<Teacher> teachers = m_teacherController.searchTeachers(text);

        ui->teacherTable->setRowCount(teachers.size());
        for (int i = 0; i < teachers.size(); ++i) {
            const Teacher& t = teachers[i];
            ui->teacherTable->setItem(i, 0, new QTableWidgetItem(QString::number(t.id())));
            ui->teacherTable->setItem(i, 1, new QTableWidgetItem(t.teacherNo()));
            ui->teacherTable->setItem(i, 2, new QTableWidgetItem(t.name()));
            ui->teacherTable->setItem(i, 3, new QTableWidgetItem(t.coursesString()));
        }
    }
}

void AdminMainWindow::onAddTeacherClicked()
{
    TeacherDialog dialog(this);
    dialog.setEditMode(false);
    
    // 加载所有可选课程
    QVector<Course> allCourses = m_courseController.getAllCourses();
    dialog.setAvailableCourses(allCourses);
    
    if (dialog.exec() == QDialog::Accepted) {
        Teacher teacher = dialog.getTeacher();
        QVector<int> selectedCourseIds = dialog.getSelectedCourseIds();
        
        if (teacher.teacherNo().isEmpty() || teacher.name().isEmpty()) {
            QMessageBox::warning(this, "提示", "工号和姓名不能为空");
            return;
        }
        
        if (m_teacherController.addTeacher(teacher, selectedCourseIds)) {
            QMessageBox::information(this, "成功", "添加教师成功");
            loadTeachers();
        } else {
            QMessageBox::warning(this, "失败", "添加教师失败，工号可能已存在");
        }
    }
}

void AdminMainWindow::onEditTeacherClicked()
{
    int row = ui->teacherTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要编辑的教师");
        return;
    }

    int id = ui->teacherTable->item(row, 0)->text().toInt();
    
    TeacherDialog dialog(this);
    dialog.setEditMode(true);
    
    // 加载所有可选课程
    QVector<Course> allCourses = m_courseController.getAllCourses();
    dialog.setAvailableCourses(allCourses);
    
    QVector<Teacher> teachers = m_teacherController.getAllTeachers();
    for (const Teacher& t : teachers) {
        if (t.id() == id) {
            dialog.setTeacher(t);
            break;
        }
    }
    
    if (dialog.exec() == QDialog::Accepted) {
        Teacher teacher = dialog.getTeacher();
        teacher.setId(id);
        QVector<int> selectedCourseIds = dialog.getSelectedCourseIds();
        
        if (m_teacherController.updateTeacher(teacher, selectedCourseIds)) {
            QMessageBox::information(this, "成功", "更新教师成功");
            loadTeachers();
        } else {
            QMessageBox::warning(this, "失败", "更新教师失败");
        }
    }
}

void AdminMainWindow::onDeleteTeacherClicked()
{
    int row = ui->teacherTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要删除的教师");
        return;
    }

    QString name = ui->teacherTable->item(row, 2)->text();
    int id = ui->teacherTable->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "确认", 
        QString("确定要删除教师 \"%1\" 吗？").arg(name),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (m_teacherController.deleteTeacher(id)) {
            QMessageBox::information(this, "成功", "删除教师成功");
            loadTeachers();
        } else {
            QMessageBox::warning(this, "失败", "删除教师失败");
        }
    }
}

void AdminMainWindow::onRefreshTeachersClicked()
{
    loadTeachers();
}

void AdminMainWindow::onSearchCourseChanged(const QString& text)
{
    if (text.isEmpty()) {
        loadCourses();
    } else {
        QVector<Course> courses = m_courseController.searchCourses(text);

        ui->courseTable->setRowCount(courses.size());
        for (int i = 0; i < courses.size(); ++i) {
            const Course& c = courses[i];
            ui->courseTable->setItem(i, 0, new QTableWidgetItem(QString::number(c.id())));
            ui->courseTable->setItem(i, 1, new QTableWidgetItem(c.courseNo()));
            ui->courseTable->setItem(i, 2, new QTableWidgetItem(c.courseName()));
            ui->courseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.credit())));
            ui->courseTable->setItem(i, 4, new QTableWidgetItem(QString::number(c.hours())));
            ui->courseTable->setItem(i, 5, new QTableWidgetItem(c.courseType()));
        }
    }
}

void AdminMainWindow::onAddCourseClicked()
{
    CourseDialog dialog(this);
    dialog.setEditMode(false);
    
    if (dialog.exec() == QDialog::Accepted) {
        Course course = dialog.getCourse();
        
        if (course.courseNo().isEmpty() || course.courseName().isEmpty()) {
            QMessageBox::warning(this, "提示", "课程号和课程名不能为空");
            return;
        }
        
        if (m_courseController.addCourse(course)) {
            QMessageBox::information(this, "成功", "添加课程成功");
            loadCourses();
        } else {
            QMessageBox::warning(this, "失败", "添加课程失败，课程号可能已存在");
        }
    }
}

void AdminMainWindow::onEditCourseClicked()
{
    int row = ui->courseTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要编辑的课程");
        return;
    }

    int id = ui->courseTable->item(row, 0)->text().toInt();
    
    CourseDialog dialog(this);
    dialog.setEditMode(true);
    
    QVector<Course> courses = m_courseController.getAllCourses();
    for (const Course& c : courses) {
        if (c.id() == id) {
            dialog.setCourse(c);
            break;
        }
    }
    
    if (dialog.exec() == QDialog::Accepted) {
        Course course = dialog.getCourse();
        course.setId(id);
        
        if (m_courseController.updateCourse(course)) {
            QMessageBox::information(this, "成功", "更新课程成功");
            loadCourses();
        } else {
            QMessageBox::warning(this, "失败", "更新课程失败");
        }
    }
}

void AdminMainWindow::onDeleteCourseClicked()
{
    int row = ui->courseTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要删除的课程");
        return;
    }

    QString name = ui->courseTable->item(row, 2)->text();
    int id = ui->courseTable->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "确认", 
        QString("确定要删除课程 \"%1\" 吗？").arg(name),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (m_courseController.deleteCourse(id)) {
            QMessageBox::information(this, "成功", "删除课程成功");
            loadCourses();
        } else {
            QMessageBox::warning(this, "失败", "删除课程失败");
        }
    }
}

void AdminMainWindow::onRefreshCoursesClicked()
{
    loadCourses();
}

void AdminMainWindow::onAddGradeClicked()
{
    GradeDialog dialog(this);
    dialog.setEditMode(false);
    dialog.setStudents(m_studentController.getAllStudents());
    dialog.setCourses(m_courseController.getAllCourses());
    
    if (dialog.exec() == QDialog::Accepted) {
        Grade grade = dialog.getGrade();
        
        if (m_gradeController.addGrade(grade)) {
            QMessageBox::information(this, "成功", "添加成绩成功");
            loadGrades();
        } else {
            QMessageBox::warning(this, "失败", "添加成绩失败，该学生该课程成绩可能已存在");
        }
    }
}

void AdminMainWindow::onEditGradeClicked()
{
    int row = ui->gradeTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要编辑的成绩");
        return;
    }

    int id = ui->gradeTable->item(row, 0)->text().toInt();
    
    GradeDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setStudents(m_studentController.getAllStudents());
    dialog.setCourses(m_courseController.getAllCourses());
    
    QVector<Grade> grades = m_gradeController.getAllGrades();
    for (const Grade& g : grades) {
        if (g.id() == id) {
            dialog.setGrade(g);
            break;
        }
    }
    
    if (dialog.exec() == QDialog::Accepted) {
        Grade grade = dialog.getGrade();
        grade.setId(id);
        
        if (m_gradeController.updateGrade(grade)) {
            QMessageBox::information(this, "成功", "更新成绩成功");
            loadGrades();
        } else {
            QMessageBox::warning(this, "失败", "更新成绩失败");
        }
    }
}

void AdminMainWindow::onDeleteGradeClicked()
{
    int row = ui->gradeTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要删除的成绩");
        return;
    }

    int id = ui->gradeTable->item(row, 0)->text().toInt();
    
    auto reply = QMessageBox::question(this, "确认", "确定要删除该成绩记录吗？",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (m_gradeController.deleteGrade(id)) {
            QMessageBox::information(this, "成功", "删除成绩成功");
            loadGrades();
        } else {
            QMessageBox::warning(this, "失败", "删除成绩失败");
        }
    }
}

void AdminMainWindow::onRefreshGradesClicked()
{
    loadGrades();
}

void AdminMainWindow::onSearchGradeChanged(const QString& text)
{
    if (text.isEmpty()) {
        loadGrades();
    } else {
        QVector<Student> students = m_studentController.getAllStudents();
        QVector<Course> courses = m_courseController.getAllCourses();
        QVector<Grade> grades = m_gradeController.searchGrades(text, students, courses);

        QMap<int, Student> studentMap;
        QMap<int, Course> courseMap;
        for (const Student& s : students) {
            studentMap[s.id()] = s;
        }
        for (const Course& c : courses) {
            courseMap[c.id()] = c;
        }

        ui->gradeTable->setRowCount(grades.size());
        for (int i = 0; i < grades.size(); ++i) {
            const Grade& g = grades[i];
            const Student& s = studentMap.value(g.studentId());
            const Course& c = courseMap.value(g.courseId());

            ui->gradeTable->setItem(i, 0, new QTableWidgetItem(QString::number(g.id())));
            ui->gradeTable->setItem(i, 1, new QTableWidgetItem(s.name()));
            ui->gradeTable->setItem(i, 2, new QTableWidgetItem(s.studentNo()));
            ui->gradeTable->setItem(i, 3, new QTableWidgetItem(c.courseName()));
            ui->gradeTable->setItem(i, 4, new QTableWidgetItem(c.courseNo()));
            ui->gradeTable->setItem(i, 5, new QTableWidgetItem(QString::number(g.grade())));
        }
    }
}

void AdminMainWindow::loadStudents()
{
    QVector<Student> students = m_studentController.getAllStudents();
    ui->studentTable->setRowCount(students.size());

    for (int i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        ui->studentTable->setItem(i, 0, new QTableWidgetItem(QString::number(s.id())));
        ui->studentTable->setItem(i, 1, new QTableWidgetItem(s.studentNo()));
        ui->studentTable->setItem(i, 2, new QTableWidgetItem(s.name()));
        ui->studentTable->setItem(i, 3, new QTableWidgetItem(s.className()));
        ui->studentTable->setItem(i, 4, new QTableWidgetItem(s.major()));
    }

    statusBar()->showMessage(QString("共 %1 名学生").arg(students.size()));
}

void AdminMainWindow::loadTeachers()
{
    QVector<Teacher> teachers = m_teacherController.getAllTeachers();
    ui->teacherTable->setRowCount(teachers.size());

    for (int i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        ui->teacherTable->setItem(i, 0, new QTableWidgetItem(QString::number(t.id())));
        ui->teacherTable->setItem(i, 1, new QTableWidgetItem(t.teacherNo()));
        ui->teacherTable->setItem(i, 2, new QTableWidgetItem(t.name()));
        ui->teacherTable->setItem(i, 3, new QTableWidgetItem(t.coursesString()));
    }

    statusBar()->showMessage(QString("共 %1 名教师").arg(teachers.size()));
}

void AdminMainWindow::loadCourses()
{
    QVector<Course> courses = m_courseController.getAllCourses();

    ui->courseTable->setRowCount(courses.size());

    for (int i = 0; i < courses.size(); ++i) {
        const Course& c = courses[i];
        ui->courseTable->setItem(i, 0, new QTableWidgetItem(QString::number(c.id())));
        ui->courseTable->setItem(i, 1, new QTableWidgetItem(c.courseNo()));
        ui->courseTable->setItem(i, 2, new QTableWidgetItem(c.courseName()));
        ui->courseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.credit())));
        ui->courseTable->setItem(i, 4, new QTableWidgetItem(QString::number(c.hours())));
        ui->courseTable->setItem(i, 5, new QTableWidgetItem(c.courseType()));
    }

    statusBar()->showMessage(QString("共 %1 门课程").arg(courses.size()));
}

void AdminMainWindow::loadGrades()
{
    QVector<Grade> grades = m_gradeController.getAllGrades();
    QVector<Student> students = m_studentController.getAllStudents();
    QVector<Course> courses = m_courseController.getAllCourses();

    QMap<int, Student> studentMap;
    QMap<int, Course> courseMap;
    for (const Student& s : students) {
        studentMap[s.id()] = s;
    }
    for (const Course& c : courses) {
        courseMap[c.id()] = c;
    }

    ui->gradeTable->setRowCount(grades.size());

    for (int i = 0; i < grades.size(); ++i) {
        const Grade& g = grades[i];
        const Student& s = studentMap.value(g.studentId());
        const Course& c = courseMap.value(g.courseId());

        ui->gradeTable->setItem(i, 0, new QTableWidgetItem(QString::number(g.id())));
        ui->gradeTable->setItem(i, 1, new QTableWidgetItem(s.name()));
        ui->gradeTable->setItem(i, 2, new QTableWidgetItem(s.studentNo()));
        ui->gradeTable->setItem(i, 3, new QTableWidgetItem(c.courseName()));
        ui->gradeTable->setItem(i, 4, new QTableWidgetItem(c.courseNo()));
        ui->gradeTable->setItem(i, 5, new QTableWidgetItem(QString::number(g.grade())));
    }

    statusBar()->showMessage(QString("共 %1 条成绩记录").arg(grades.size()));
}

void AdminMainWindow::loadAccounts()
{
    UserDAO userDAO;
    QVector<User> users = userDAO.findAll();

    ui->accountTable->setRowCount(users.size());

    for (int i = 0; i < users.size(); ++i) {
        const User& u = users[i];
        ui->accountTable->setItem(i, 0, new QTableWidgetItem(QString::number(u.id())));
        ui->accountTable->setItem(i, 1, new QTableWidgetItem(u.username()));
        ui->accountTable->setItem(i, 2, new QTableWidgetItem(u.username()));
        ui->accountTable->setItem(i, 3, new QTableWidgetItem("已设置"));

        QString roleText;
        if (u.role() == "admin") roleText = "管理员";
        else if (u.role() == "teacher") roleText = "教师";
        else if (u.role() == "student") roleText = "学生";
        else roleText = u.role();

        ui->accountTable->setItem(i, 4, new QTableWidgetItem(roleText));
    }

    statusBar()->showMessage(QString("共 %1 个账号").arg(users.size()));
}

void AdminMainWindow::onStudentTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void AdminMainWindow::onTeacherTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void AdminMainWindow::onCourseTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void AdminMainWindow::onGradeTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void AdminMainWindow::onAccountTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void AdminMainWindow::onAddAccountClicked()
{
    AccountDialog dialog(this);
    dialog.setEditMode(false);
    
    if (dialog.exec() == QDialog::Accepted) {
        User user = dialog.getUser();
        QString password = dialog.getPassword();
        QString confirmPassword = dialog.getConfirmPassword();
        
        // 验证输入
        if (user.username().isEmpty()) {
            QMessageBox::warning(this, "警告", "用户名不能为空");
            return;
        }
        
        if (password.isEmpty()) {
            QMessageBox::warning(this, "警告", "密码不能为空");
            return;
        }
        
        if (password != confirmPassword) {
            QMessageBox::warning(this, "警告", "两次输入的密码不一致");
            return;
        }
        
        // 检查用户名是否已存在
        UserDAO userDAO;
        auto existingUser = userDAO.findByUsername(user.username());
        if (existingUser.has_value()) {
            QMessageBox::warning(this, "警告", "该用户名已存在");
            return;
        }
        
        // 生成盐值并加密密码
        QString salt = PasswordHasher::generateSalt();
        QString hashedPassword = PasswordHasher::hashPassword(password, salt);
        
        user.setPassword(hashedPassword);
        user.setSalt(salt);
        
        if (userDAO.insert(user)) {
            QMessageBox::information(this, "成功", "账号添加成功");
            loadAccounts();
        } else {
            QMessageBox::critical(this, "错误", "账号添加失败");
        }
    }
}

void AdminMainWindow::onEditAccountClicked()
{
    int row = ui->accountTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "警告", "请先选择一个账号");
        return;
    }
    
    int userId = ui->accountTable->item(row, 0)->text().toInt();
    QString username = ui->accountTable->item(row, 1)->text();
    QString role = ui->accountTable->item(row, 4)->text();
    
    // 转换角色显示文本为数据库值
    QString roleValue;
    if (role == "管理员") roleValue = "admin";
    else if (role == "教师") roleValue = "teacher";
    else if (role == "学生") roleValue = "student";
    else roleValue = role;
    
    User user;
    user.setId(userId);
    user.setUsername(username);
    user.setRole(roleValue);
    
    AccountDialog dialog(this);
    dialog.setEditMode(true);
    dialog.setUser(user);
    
    if (dialog.exec() == QDialog::Accepted) {
        User updatedUser = dialog.getUser();
        QString password = dialog.getPassword();
        QString confirmPassword = dialog.getConfirmPassword();
        
        // 验证密码（如果填写了）
        if (!password.isEmpty() && password != confirmPassword) {
            QMessageBox::warning(this, "警告", "两次输入的密码不一致");
            return;
        }
        
        UserDAO userDAO;
        
        // 如果填写了新密码，则更新密码
        if (!password.isEmpty()) {
            QString salt = PasswordHasher::generateSalt();
            QString hashedPassword = PasswordHasher::hashPassword(password, salt);
            updatedUser.setPassword(hashedPassword);
            updatedUser.setSalt(salt);
            
            if (userDAO.updateWithPassword(updatedUser)) {
                QMessageBox::information(this, "成功", "账号修改成功");
                loadAccounts();
            } else {
                QMessageBox::critical(this, "错误", "账号修改失败");
            }
        } else {
            // 只更新角色
            if (userDAO.updateRole(updatedUser)) {
                QMessageBox::information(this, "成功", "账号修改成功");
                loadAccounts();
            } else {
                QMessageBox::critical(this, "错误", "账号修改失败");
            }
        }
    }
}

void AdminMainWindow::onDeleteAccountClicked()
{
    int row = ui->accountTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "警告", "请先选择一个账号");
        return;
    }
    
    int userId = ui->accountTable->item(row, 0)->text().toInt();
    QString username = ui->accountTable->item(row, 1)->text();
    
    // 防止删除当前登录的管理员账号
    if (username == m_currentUser.username()) {
        QMessageBox::warning(this, "警告", "不能删除当前登录的账号");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "确认删除", 
        QString("确定要删除账号 '%1' 吗？").arg(username),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        UserDAO userDAO;
        if (userDAO.remove(userId)) {
            QMessageBox::information(this, "成功", "账号删除成功");
            loadAccounts();
        } else {
            QMessageBox::critical(this, "错误", "账号删除失败");
        }
    }
}

void AdminMainWindow::onRefreshAccountsClicked()
{
    loadAccounts();
}

void AdminMainWindow::onSearchAccountChanged(const QString& text)
{
    if (text.isEmpty()) {
        loadAccounts();
    } else {
        UserDAO userDAO;
        QVector<User> allUsers = userDAO.findAll();
        QVector<User> filteredUsers;

        for (const User& u : allUsers) {
            if (u.username().contains(text, Qt::CaseInsensitive)) {
                filteredUsers.append(u);
            }
        }

        ui->accountTable->setRowCount(filteredUsers.size());
        for (int i = 0; i < filteredUsers.size(); ++i) {
            const User& u = filteredUsers[i];
            ui->accountTable->setItem(i, 0, new QTableWidgetItem(QString::number(u.id())));
            ui->accountTable->setItem(i, 1, new QTableWidgetItem(u.username()));
            ui->accountTable->setItem(i, 2, new QTableWidgetItem(u.username()));
            ui->accountTable->setItem(i, 3, new QTableWidgetItem("已设置"));

            QString roleText;
            if (u.role() == "admin") roleText = "管理员";
            else if (u.role() == "teacher") roleText = "教师";
            else if (u.role() == "student") roleText = "学生";
            else roleText = u.role();

            ui->accountTable->setItem(i, 4, new QTableWidgetItem(roleText));
        }
    }
}
