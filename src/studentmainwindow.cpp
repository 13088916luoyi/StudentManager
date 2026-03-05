#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"
#include "authcontroller.h"
#include "studentdao.h"
#include "studentprofiledialog.h"
#include "gradedao.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QButtonGroup>

StudentMainWindow::StudentMainWindow(const User& user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMainWindow),
    m_currentUser(user)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 - 学生");

    StudentDAO studentDAO;
    auto studentOpt = studentDAO.findByUserId(user.id());
    if (studentOpt.has_value()) {
        m_studentId = studentOpt->id();
        m_currentStudent = studentOpt.value();
    }

    QButtonGroup* navGroup = new QButtonGroup(this);
    navGroup->addButton(ui->navProfileButton, 0);
    navGroup->addButton(ui->navCoursesButton, 1);
    navGroup->addButton(ui->navGradesButton, 2);
    navGroup->setExclusive(true);

    connect(navGroup, QOverload<int>::of(&QButtonGroup::idClicked), this, [this](int id) {
        updateNavButtons(id);
        switch (id) {
            case 0: onNavProfileClicked(); break;
            case 1: onNavCoursesClicked(); break;
            case 2: onNavGradesClicked(); break;
        }
    });

    connect(ui->logoutButton, &QPushButton::clicked, this, &StudentMainWindow::onLogoutClicked);
    connect(ui->editProfileButton, &QPushButton::clicked, this, &StudentMainWindow::onEditProfileClicked);
    connect(ui->selectCourseButton, &QPushButton::clicked, this, &StudentMainWindow::onSelectCourseClicked);
    connect(ui->dropCourseButton, &QPushButton::clicked, this, &StudentMainWindow::onDropCourseClicked);

    connect(ui->refreshMyCoursesButton, &QPushButton::clicked, this, [this]() {
        loadMyCourses();
        loadAvailableCourses();
    });
    connect(ui->refreshSelectCourseButton, &QPushButton::clicked, this, [this]() {
        loadMyCourses();
        loadAvailableCourses();
    });
    connect(ui->refreshGradesButton, &QPushButton::clicked, this, &StudentMainWindow::onNavGradesClicked);

    // 连接表格悬停信号以显示tooltip
    connect(ui->myCourseTable, &QTableWidget::itemEntered, this, &StudentMainWindow::onMyCourseTableItemEntered);
    connect(ui->availableCourseTable, &QTableWidget::itemEntered, this, &StudentMainWindow::onAvailableCourseTableItemEntered);
    connect(ui->gradeTable, &QTableWidget::itemEntered, this, &StudentMainWindow::onGradeTableItemEntered);

    // 启用鼠标追踪
    ui->myCourseTable->setMouseTracking(true);
    ui->availableCourseTable->setMouseTracking(true);
    ui->gradeTable->setMouseTracking(true);

    QString tableStyle = "QTableWidget::item:selected { background-color: #4a90d9; color: white; }";

    QFont tableFont;
    tableFont.setPointSize(12);

    ui->myCourseTable->setFont(tableFont);
    ui->myCourseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->myCourseTable->setStyleSheet(tableStyle);
    ui->myCourseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->myCourseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->myCourseTable->verticalHeader()->setDefaultSectionSize(35);
    ui->myCourseTable->verticalHeader()->setFixedWidth(50);

    ui->availableCourseTable->setFont(tableFont);
    ui->availableCourseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->availableCourseTable->setStyleSheet(tableStyle);
    ui->availableCourseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->availableCourseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->availableCourseTable->verticalHeader()->setDefaultSectionSize(35);
    ui->availableCourseTable->verticalHeader()->setFixedWidth(50);

    ui->gradeTable->setFont(tableFont);
    ui->gradeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->gradeTable->setStyleSheet(tableStyle);
    ui->gradeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->gradeTable->verticalHeader()->setDefaultSectionSize(35);
    ui->gradeTable->verticalHeader()->setFixedWidth(50);

    onNavProfileClicked();
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
}

void StudentMainWindow::updateNavButtons(int index)
{
    ui->navProfileButton->setChecked(index == 0);
    ui->navCoursesButton->setChecked(index == 1);
    ui->navGradesButton->setChecked(index == 2);
}

void StudentMainWindow::onNavProfileClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
    loadProfile();
}

void StudentMainWindow::onNavCoursesClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->coursesPage);
    loadMyCourses();
    loadAvailableCourses();
}

void StudentMainWindow::onNavGradesClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->gradesPage);
    loadMyGrades();
}

void StudentMainWindow::onLogoutClicked()
{
    AuthController::instance().logout();
    close();
}

void StudentMainWindow::onEditProfileClicked()
{
    StudentProfileDialog dialog(this);
    dialog.setStudent(m_currentStudent);

    if (dialog.exec() == QDialog::Accepted) {
        Student updatedStudent = dialog.getStudent();

        if (m_studentController.updateStudent(updatedStudent)) {
            m_currentStudent = updatedStudent;
            QMessageBox::information(this, "成功", "个人信息更新成功");
            loadProfile();
        } else {
            QMessageBox::warning(this, "失败", "个人信息更新失败");
        }
    }
}

void StudentMainWindow::onSelectCourseClicked()
{
    int row = ui->availableCourseTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要选的课程");
        return;
    }

    int courseId = ui->availableCourseTable->item(row, 0)->data(Qt::UserRole).toInt();
    QString courseName = ui->availableCourseTable->item(row, 1)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认选课",
        QString("确定要选择课程【%1】吗？").arg(courseName),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        Grade grade;
        grade.setStudentId(m_studentId);
        grade.setCourseId(courseId);
        grade.setGrade(0);

        if (m_gradeController.addGrade(grade)) {
            QMessageBox::information(this, "成功", "选课成功");
            loadMyCourses();
            loadAvailableCourses();
        } else {
            QMessageBox::warning(this, "失败", "选课失败，可能已经选择了该课程");
        }
    }
}

void StudentMainWindow::onDropCourseClicked()
{
    int row = ui->myCourseTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "提示", "请选择要退的课程");
        return;
    }

    int courseId = ui->myCourseTable->item(row, 0)->data(Qt::UserRole).toInt();
    QString courseName = ui->myCourseTable->item(row, 1)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认退课",
        QString("确定要退选课程【%1】吗？\n退课后成绩记录将被删除！").arg(courseName),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        GradeDAO gradeDAO;
        QVector<Grade> grades = gradeDAO.findByStudentId(m_studentId);

        int gradeId = -1;
        for (const Grade& g : grades) {
            if (g.courseId() == courseId) {
                gradeId = g.id();
                break;
            }
        }

        if (gradeId > 0 && m_gradeController.deleteGrade(gradeId)) {
            QMessageBox::information(this, "成功", "退课成功");
            loadMyCourses();
            loadAvailableCourses();
        } else {
            QMessageBox::warning(this, "失败", "退课失败");
        }
    }
}

void StudentMainWindow::loadProfile()
{
    StudentDAO studentDAO;
    auto studentOpt = studentDAO.findByUserId(m_currentUser.id());

    if (studentOpt.has_value()) {
        Student s = studentOpt.value();
        m_studentId = s.id();
        m_currentStudent = s;

        ui->studentNoLabel->setText(s.studentNo());
        ui->nameLabel->setText(s.name());
        ui->classLabel->setText(s.className());
        ui->majorLabel->setText(s.major());

        statusBar()->showMessage(QString("欢迎，%1 同学").arg(s.name()));
    } else {
        ui->nameLabel->setText(m_currentUser.username());
        statusBar()->showMessage(QString("当前用户: %1").arg(m_currentUser.username()));
    }
}

void StudentMainWindow::loadMyCourses()
{
    QVector<Grade> grades = m_gradeController.getGradesByStudent(m_studentId);
    QVector<Course> allCourses = m_courseController.getAllCourses();

    QMap<int, Course> courseMap;
    for (const Course& c : allCourses) {
        courseMap[c.id()] = c;
    }

    QVector<Course> myCourses;
    QSet<int> addedCourseIds;
    for (const Grade& g : grades) {
        if (!addedCourseIds.contains(g.courseId()) && courseMap.contains(g.courseId())) {
            myCourses.append(courseMap[g.courseId()]);
            addedCourseIds.insert(g.courseId());
        }
    }

    ui->myCourseTable->clear();
    ui->myCourseTable->setRowCount(myCourses.size());
    ui->myCourseTable->setColumnCount(4);
    ui->myCourseTable->setHorizontalHeaderLabels({"课程号", "课程名", "学分", "学时"});
    ui->myCourseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < myCourses.size(); ++i) {
        const Course& c = myCourses[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(c.courseNo());
        item0->setData(Qt::UserRole, c.id());
        ui->myCourseTable->setItem(i, 0, item0);
        ui->myCourseTable->setItem(i, 1, new QTableWidgetItem(c.courseName()));
        ui->myCourseTable->setItem(i, 2, new QTableWidgetItem(QString::number(c.credit())));
        ui->myCourseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.hours())));
    }

    statusBar()->showMessage(QString("已选 %1 门课程").arg(myCourses.size()));
}

void StudentMainWindow::loadMyGrades()
{
    QVector<Grade> grades = m_gradeController.getGradesByStudent(m_studentId);
    QVector<Course> allCourses = m_courseController.getAllCourses();

    QMap<int, QString> courseMap;
    for (const Course& c : allCourses) {
        courseMap[c.id()] = c.courseName();
    }

    ui->gradeTable->clear();
    ui->gradeTable->setRowCount(grades.size());
    ui->gradeTable->setColumnCount(2);
    ui->gradeTable->setHorizontalHeaderLabels({"课程", "成绩"});
    ui->gradeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    double sum = 0;
    double maxGrade = 0;
    double minGrade = 100;

    for (int i = 0; i < grades.size(); ++i) {
        const Grade& g = grades[i];
        ui->gradeTable->setItem(i, 0, new QTableWidgetItem(courseMap.value(g.courseId(), "未知")));
        ui->gradeTable->setItem(i, 1, new QTableWidgetItem(QString::number(g.grade())));

        sum += g.grade();
        if (g.grade() > maxGrade) maxGrade = g.grade();
        if (g.grade() < minGrade) minGrade = g.grade();
    }

    if (grades.size() > 0) {
        double avg = sum / grades.size();
        ui->avgLabel->setText(QString("平均分：%1").arg(QString::number(avg, 'f', 1)));
        ui->maxLabel->setText(QString("最高分：%1").arg(maxGrade));
        ui->minLabel->setText(QString("最低分：%1").arg(minGrade));
        ui->countLabel->setText(QString("课程数：%1").arg(grades.size()));
    } else {
        ui->avgLabel->setText("平均分：-");
        ui->maxLabel->setText("最高分：-");
        ui->minLabel->setText("最低分：-");
        ui->countLabel->setText("课程数：0");
    }

    statusBar()->showMessage(QString("共 %1 条成绩记录").arg(grades.size()));
}

void StudentMainWindow::loadAvailableCourses()
{
    QVector<Grade> myGrades = m_gradeController.getGradesByStudent(m_studentId);
    QVector<Course> allCourses = m_courseController.getAllCourses();

    QSet<int> selectedCourseIds;
    for (const Grade& g : myGrades) {
        selectedCourseIds.insert(g.courseId());
    }

    QVector<Course> availableCourses;
    for (const Course& c : allCourses) {
        if (!selectedCourseIds.contains(c.id())) {
            availableCourses.append(c);
        }
    }

    ui->availableCourseTable->clear();
    ui->availableCourseTable->setRowCount(availableCourses.size());
    ui->availableCourseTable->setColumnCount(4);
    ui->availableCourseTable->setHorizontalHeaderLabels({"课程号", "课程名", "学分", "学时"});
    ui->availableCourseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < availableCourses.size(); ++i) {
        const Course& c = availableCourses[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(c.courseNo());
        item0->setData(Qt::UserRole, c.id());
        ui->availableCourseTable->setItem(i, 0, item0);
        ui->availableCourseTable->setItem(i, 1, new QTableWidgetItem(c.courseName()));
        ui->availableCourseTable->setItem(i, 2, new QTableWidgetItem(QString::number(c.credit())));
        ui->availableCourseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.hours())));
    }
}

// 鼠标悬停显示单元格全文
void StudentMainWindow::onMyCourseTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void StudentMainWindow::onAvailableCourseTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}

void StudentMainWindow::onGradeTableItemEntered(QTableWidgetItem* item)
{
    if (item) {
        item->setToolTip(item->text());
    }
}
