/********************************************************************************
** Form generated from reading UI file 'adminmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINWINDOW_H
#define UI_ADMINMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QWidget *navPanel;
    QVBoxLayout *verticalLayout_nav;
    QLabel *titleLabel;
    QFrame *line_1;
    QPushButton *navStudentButton;
    QPushButton *navTeacherButton;
    QPushButton *navCourseButton;
    QPushButton *navGradeButton;
    QPushButton *navAccountButton;
    QSpacerItem *verticalSpacer_nav;
    QFrame *line_2;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *studentPage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *addStudentButton;
    QPushButton *editStudentButton;
    QPushButton *deleteStudentButton;
    QPushButton *refreshStudentButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *studentSearchEdit;
    QTableWidget *studentTable;
    QWidget *teacherPage;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addTeacherButton;
    QPushButton *editTeacherButton;
    QPushButton *deleteTeacherButton;
    QPushButton *refreshTeacherButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *teacherSearchEdit;
    QTableWidget *teacherTable;
    QWidget *coursePage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addCourseButton;
    QPushButton *editCourseButton;
    QPushButton *deleteCourseButton;
    QPushButton *refreshCourseButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *courseSearchEdit;
    QTableWidget *courseTable;
    QWidget *gradePage;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addGradeButton;
    QPushButton *editGradeButton;
    QPushButton *deleteGradeButton;
    QPushButton *refreshGradeButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLineEdit *gradeSearchEdit;
    QTableWidget *gradeTable;
    QWidget *accountPage;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addAccountButton;
    QPushButton *editAccountButton;
    QPushButton *deleteAccountButton;
    QPushButton *refreshAccountButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLineEdit *accountSearchEdit;
    QTableWidget *accountTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainWindow)
    {
        if (AdminMainWindow->objectName().isEmpty())
            AdminMainWindow->setObjectName("AdminMainWindow");
        AdminMainWindow->resize(1200, 750);
        centralwidget = new QWidget(AdminMainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setSpacing(0);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        horizontalLayout_main->setContentsMargins(0, 0, 0, 0);
        navPanel = new QWidget(centralwidget);
        navPanel->setObjectName("navPanel");
        navPanel->setMinimumSize(QSize(150, 0));
        navPanel->setMaximumSize(QSize(150, 16777215));
        navPanel->setStyleSheet(QString::fromUtf8("background-color: #2c3e50;"));
        verticalLayout_nav = new QVBoxLayout(navPanel);
        verticalLayout_nav->setSpacing(5);
        verticalLayout_nav->setObjectName("verticalLayout_nav");
        verticalLayout_nav->setContentsMargins(0, 10, 0, 10);
        titleLabel = new QLabel(navPanel);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("color: white; font-size: 16px; font-weight: bold; padding: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_nav->addWidget(titleLabel);

        line_1 = new QFrame(navPanel);
        line_1->setObjectName("line_1");
        line_1->setStyleSheet(QString::fromUtf8("background-color: #34495e;"));
        line_1->setFrameShape(QFrame::Shape::HLine);
        line_1->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_nav->addWidget(line_1);

        navStudentButton = new QPushButton(navPanel);
        navStudentButton->setObjectName("navStudentButton");
        navStudentButton->setMinimumSize(QSize(0, 45));
        navStudentButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navStudentButton->setCheckable(true);
        navStudentButton->setChecked(true);

        verticalLayout_nav->addWidget(navStudentButton);

        navTeacherButton = new QPushButton(navPanel);
        navTeacherButton->setObjectName("navTeacherButton");
        navTeacherButton->setMinimumSize(QSize(0, 45));
        navTeacherButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navTeacherButton->setCheckable(true);

        verticalLayout_nav->addWidget(navTeacherButton);

        navCourseButton = new QPushButton(navPanel);
        navCourseButton->setObjectName("navCourseButton");
        navCourseButton->setMinimumSize(QSize(0, 45));
        navCourseButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navCourseButton->setCheckable(true);

        verticalLayout_nav->addWidget(navCourseButton);

        navGradeButton = new QPushButton(navPanel);
        navGradeButton->setObjectName("navGradeButton");
        navGradeButton->setMinimumSize(QSize(0, 45));
        navGradeButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navGradeButton->setCheckable(true);

        verticalLayout_nav->addWidget(navGradeButton);

        navAccountButton = new QPushButton(navPanel);
        navAccountButton->setObjectName("navAccountButton");
        navAccountButton->setMinimumSize(QSize(0, 45));
        navAccountButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navAccountButton->setCheckable(true);

        verticalLayout_nav->addWidget(navAccountButton);

        verticalSpacer_nav = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_nav->addItem(verticalSpacer_nav);

        line_2 = new QFrame(navPanel);
        line_2->setObjectName("line_2");
        line_2->setStyleSheet(QString::fromUtf8("background-color: #34495e;"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_nav->addWidget(line_2);

        logoutButton = new QPushButton(navPanel);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(0, 45));
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton { color: #e74c3c; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #c0392b; color: white; }"));

        verticalLayout_nav->addWidget(logoutButton);


        horizontalLayout_main->addWidget(navPanel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        studentPage = new QWidget();
        studentPage->setObjectName("studentPage");
        verticalLayout_2 = new QVBoxLayout(studentPage);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addStudentButton = new QPushButton(studentPage);
        addStudentButton->setObjectName("addStudentButton");
        addStudentButton->setMinimumSize(QSize(80, 32));
        QFont font;
        font.setPointSize(10);
        addStudentButton->setFont(font);

        horizontalLayout->addWidget(addStudentButton);

        editStudentButton = new QPushButton(studentPage);
        editStudentButton->setObjectName("editStudentButton");
        editStudentButton->setMinimumSize(QSize(80, 32));
        editStudentButton->setFont(font);

        horizontalLayout->addWidget(editStudentButton);

        deleteStudentButton = new QPushButton(studentPage);
        deleteStudentButton->setObjectName("deleteStudentButton");
        deleteStudentButton->setMinimumSize(QSize(80, 32));
        deleteStudentButton->setFont(font);

        horizontalLayout->addWidget(deleteStudentButton);

        refreshStudentButton = new QPushButton(studentPage);
        refreshStudentButton->setObjectName("refreshStudentButton");
        refreshStudentButton->setMinimumSize(QSize(80, 32));
        refreshStudentButton->setFont(font);

        horizontalLayout->addWidget(refreshStudentButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(studentPage);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        studentSearchEdit = new QLineEdit(studentPage);
        studentSearchEdit->setObjectName("studentSearchEdit");
        studentSearchEdit->setMinimumSize(QSize(200, 32));
        studentSearchEdit->setFont(font);

        horizontalLayout->addWidget(studentSearchEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        studentTable = new QTableWidget(studentPage);
        studentTable->setObjectName("studentTable");
        QFont font1;
        font1.setPointSize(11);
        studentTable->setFont(font1);
        studentTable->setSelectionMode(QAbstractItemView::SingleSelection);
        studentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        studentTable->setSortingEnabled(true);
        studentTable->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(studentTable);

        stackedWidget->addWidget(studentPage);
        teacherPage = new QWidget();
        teacherPage->setObjectName("teacherPage");
        verticalLayout_3 = new QVBoxLayout(teacherPage);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addTeacherButton = new QPushButton(teacherPage);
        addTeacherButton->setObjectName("addTeacherButton");
        addTeacherButton->setMinimumSize(QSize(80, 32));
        addTeacherButton->setFont(font);

        horizontalLayout_2->addWidget(addTeacherButton);

        editTeacherButton = new QPushButton(teacherPage);
        editTeacherButton->setObjectName("editTeacherButton");
        editTeacherButton->setMinimumSize(QSize(80, 32));
        editTeacherButton->setFont(font);

        horizontalLayout_2->addWidget(editTeacherButton);

        deleteTeacherButton = new QPushButton(teacherPage);
        deleteTeacherButton->setObjectName("deleteTeacherButton");
        deleteTeacherButton->setMinimumSize(QSize(80, 32));
        deleteTeacherButton->setFont(font);

        horizontalLayout_2->addWidget(deleteTeacherButton);

        refreshTeacherButton = new QPushButton(teacherPage);
        refreshTeacherButton->setObjectName("refreshTeacherButton");
        refreshTeacherButton->setMinimumSize(QSize(80, 32));
        refreshTeacherButton->setFont(font);

        horizontalLayout_2->addWidget(refreshTeacherButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(teacherPage);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        teacherSearchEdit = new QLineEdit(teacherPage);
        teacherSearchEdit->setObjectName("teacherSearchEdit");
        teacherSearchEdit->setMinimumSize(QSize(200, 32));
        teacherSearchEdit->setFont(font);

        horizontalLayout_2->addWidget(teacherSearchEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        teacherTable = new QTableWidget(teacherPage);
        teacherTable->setObjectName("teacherTable");
        teacherTable->setFont(font1);
        teacherTable->setSelectionMode(QAbstractItemView::SingleSelection);
        teacherTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        teacherTable->setSortingEnabled(true);
        teacherTable->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(teacherTable);

        stackedWidget->addWidget(teacherPage);
        coursePage = new QWidget();
        coursePage->setObjectName("coursePage");
        verticalLayout_4 = new QVBoxLayout(coursePage);
        verticalLayout_4->setSpacing(8);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addCourseButton = new QPushButton(coursePage);
        addCourseButton->setObjectName("addCourseButton");
        addCourseButton->setMinimumSize(QSize(80, 32));
        addCourseButton->setFont(font);

        horizontalLayout_3->addWidget(addCourseButton);

        editCourseButton = new QPushButton(coursePage);
        editCourseButton->setObjectName("editCourseButton");
        editCourseButton->setMinimumSize(QSize(80, 32));
        editCourseButton->setFont(font);

        horizontalLayout_3->addWidget(editCourseButton);

        deleteCourseButton = new QPushButton(coursePage);
        deleteCourseButton->setObjectName("deleteCourseButton");
        deleteCourseButton->setMinimumSize(QSize(80, 32));
        deleteCourseButton->setFont(font);

        horizontalLayout_3->addWidget(deleteCourseButton);

        refreshCourseButton = new QPushButton(coursePage);
        refreshCourseButton->setObjectName("refreshCourseButton");
        refreshCourseButton->setMinimumSize(QSize(80, 32));
        refreshCourseButton->setFont(font);

        horizontalLayout_3->addWidget(refreshCourseButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_3 = new QLabel(coursePage);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        courseSearchEdit = new QLineEdit(coursePage);
        courseSearchEdit->setObjectName("courseSearchEdit");
        courseSearchEdit->setMinimumSize(QSize(200, 32));
        courseSearchEdit->setFont(font);

        horizontalLayout_3->addWidget(courseSearchEdit);


        verticalLayout_4->addLayout(horizontalLayout_3);

        courseTable = new QTableWidget(coursePage);
        courseTable->setObjectName("courseTable");
        courseTable->setFont(font1);
        courseTable->setSelectionMode(QAbstractItemView::SingleSelection);
        courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        courseTable->setSortingEnabled(true);
        courseTable->setAlternatingRowColors(true);

        verticalLayout_4->addWidget(courseTable);

        stackedWidget->addWidget(coursePage);
        gradePage = new QWidget();
        gradePage->setObjectName("gradePage");
        verticalLayout_5 = new QVBoxLayout(gradePage);
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addGradeButton = new QPushButton(gradePage);
        addGradeButton->setObjectName("addGradeButton");
        addGradeButton->setMinimumSize(QSize(80, 32));
        addGradeButton->setFont(font);

        horizontalLayout_4->addWidget(addGradeButton);

        editGradeButton = new QPushButton(gradePage);
        editGradeButton->setObjectName("editGradeButton");
        editGradeButton->setMinimumSize(QSize(80, 32));
        editGradeButton->setFont(font);

        horizontalLayout_4->addWidget(editGradeButton);

        deleteGradeButton = new QPushButton(gradePage);
        deleteGradeButton->setObjectName("deleteGradeButton");
        deleteGradeButton->setMinimumSize(QSize(80, 32));
        deleteGradeButton->setFont(font);

        horizontalLayout_4->addWidget(deleteGradeButton);

        refreshGradeButton = new QPushButton(gradePage);
        refreshGradeButton->setObjectName("refreshGradeButton");
        refreshGradeButton->setMinimumSize(QSize(80, 32));
        refreshGradeButton->setFont(font);

        horizontalLayout_4->addWidget(refreshGradeButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_4 = new QLabel(gradePage);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        gradeSearchEdit = new QLineEdit(gradePage);
        gradeSearchEdit->setObjectName("gradeSearchEdit");
        gradeSearchEdit->setMinimumSize(QSize(200, 32));
        gradeSearchEdit->setFont(font);

        horizontalLayout_4->addWidget(gradeSearchEdit);


        verticalLayout_5->addLayout(horizontalLayout_4);

        gradeTable = new QTableWidget(gradePage);
        gradeTable->setObjectName("gradeTable");
        gradeTable->setFont(font1);
        gradeTable->setSelectionMode(QAbstractItemView::SingleSelection);
        gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        gradeTable->setSortingEnabled(true);
        gradeTable->setAlternatingRowColors(true);

        verticalLayout_5->addWidget(gradeTable);

        stackedWidget->addWidget(gradePage);
        accountPage = new QWidget();
        accountPage->setObjectName("accountPage");
        verticalLayout_6 = new QVBoxLayout(accountPage);
        verticalLayout_6->setSpacing(8);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addAccountButton = new QPushButton(accountPage);
        addAccountButton->setObjectName("addAccountButton");
        addAccountButton->setMinimumSize(QSize(80, 32));
        addAccountButton->setFont(font);

        horizontalLayout_5->addWidget(addAccountButton);

        editAccountButton = new QPushButton(accountPage);
        editAccountButton->setObjectName("editAccountButton");
        editAccountButton->setMinimumSize(QSize(80, 32));
        editAccountButton->setFont(font);

        horizontalLayout_5->addWidget(editAccountButton);

        deleteAccountButton = new QPushButton(accountPage);
        deleteAccountButton->setObjectName("deleteAccountButton");
        deleteAccountButton->setMinimumSize(QSize(80, 32));
        deleteAccountButton->setFont(font);

        horizontalLayout_5->addWidget(deleteAccountButton);

        refreshAccountButton = new QPushButton(accountPage);
        refreshAccountButton->setObjectName("refreshAccountButton");
        refreshAccountButton->setMinimumSize(QSize(80, 32));
        refreshAccountButton->setFont(font);

        horizontalLayout_5->addWidget(refreshAccountButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_5 = new QLabel(accountPage);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        accountSearchEdit = new QLineEdit(accountPage);
        accountSearchEdit->setObjectName("accountSearchEdit");
        accountSearchEdit->setMinimumSize(QSize(200, 32));
        accountSearchEdit->setFont(font);

        horizontalLayout_5->addWidget(accountSearchEdit);


        verticalLayout_6->addLayout(horizontalLayout_5);

        accountTable = new QTableWidget(accountPage);
        accountTable->setObjectName("accountTable");
        accountTable->setFont(font1);
        accountTable->setSelectionMode(QAbstractItemView::SingleSelection);
        accountTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        accountTable->setSortingEnabled(true);
        accountTable->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(accountTable);

        stackedWidget->addWidget(accountPage);

        horizontalLayout_main->addWidget(stackedWidget);

        AdminMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AdminMainWindow);
        statusbar->setObjectName("statusbar");
        AdminMainWindow->setStatusBar(statusbar);

        retranslateUi(AdminMainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainWindow)
    {
        AdminMainWindow->setWindowTitle(QCoreApplication::translate("AdminMainWindow", "\347\256\241\347\220\206\345\221\230\344\270\273\347\252\227\345\217\243", nullptr));
        titleLabel->setText(QCoreApplication::translate("AdminMainWindow", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        navStudentButton->setText(QCoreApplication::translate("AdminMainWindow", "  \345\255\246\347\224\237\347\256\241\347\220\206", nullptr));
        navTeacherButton->setText(QCoreApplication::translate("AdminMainWindow", "  \346\225\231\345\270\210\347\256\241\347\220\206", nullptr));
        navCourseButton->setText(QCoreApplication::translate("AdminMainWindow", "  \350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        navGradeButton->setText(QCoreApplication::translate("AdminMainWindow", "  \346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        navAccountButton->setText(QCoreApplication::translate("AdminMainWindow", "  \350\264\246\345\217\267\347\256\241\347\220\206", nullptr));
        logoutButton->setText(QCoreApplication::translate("AdminMainWindow", "  \351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        addStudentButton->setText(QCoreApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        editStudentButton->setText(QCoreApplication::translate("AdminMainWindow", "\347\274\226\350\276\221\345\255\246\347\224\237", nullptr));
        deleteStudentButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\240\351\231\244\345\255\246\347\224\237", nullptr));
        refreshStudentButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\267\346\226\260", nullptr));
        label->setText(QCoreApplication::translate("AdminMainWindow", "\346\220\234\347\264\242\357\274\232", nullptr));
        studentSearchEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "\350\276\223\345\205\245\345\255\246\345\217\267\346\210\226\345\247\223\345\220\215", nullptr));
        addTeacherButton->setText(QCoreApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\346\225\231\345\270\210", nullptr));
        editTeacherButton->setText(QCoreApplication::translate("AdminMainWindow", "\347\274\226\350\276\221\346\225\231\345\270\210", nullptr));
        deleteTeacherButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\240\351\231\244\346\225\231\345\270\210", nullptr));
        refreshTeacherButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\267\346\226\260", nullptr));
        label_2->setText(QCoreApplication::translate("AdminMainWindow", "\346\220\234\347\264\242\357\274\232", nullptr));
        teacherSearchEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "\350\276\223\345\205\245\345\267\245\345\217\267\346\210\226\345\247\223\345\220\215", nullptr));
        addCourseButton->setText(QCoreApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\350\257\276\347\250\213", nullptr));
        editCourseButton->setText(QCoreApplication::translate("AdminMainWindow", "\347\274\226\350\276\221\350\257\276\347\250\213", nullptr));
        deleteCourseButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\240\351\231\244\350\257\276\347\250\213", nullptr));
        refreshCourseButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\267\346\226\260", nullptr));
        label_3->setText(QCoreApplication::translate("AdminMainWindow", "\346\220\234\347\264\242\357\274\232", nullptr));
        courseSearchEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "\350\276\223\345\205\245\350\257\276\347\250\213\345\217\267\346\210\226\350\257\276\347\250\213\345\220\215", nullptr));
        addGradeButton->setText(QCoreApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\346\210\220\347\273\251", nullptr));
        editGradeButton->setText(QCoreApplication::translate("AdminMainWindow", "\347\274\226\350\276\221\346\210\220\347\273\251", nullptr));
        deleteGradeButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\240\351\231\244\346\210\220\347\273\251", nullptr));
        refreshGradeButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\267\346\226\260", nullptr));
        label_4->setText(QCoreApplication::translate("AdminMainWindow", "\346\220\234\347\264\242\357\274\232", nullptr));
        gradeSearchEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "\350\276\223\345\205\245\345\255\246\345\217\267\343\200\201\345\247\223\345\220\215\343\200\201\350\257\276\347\250\213\345\217\267\346\210\226\350\257\276\347\250\213\345\220\215", nullptr));
        addAccountButton->setText(QCoreApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\350\264\246\345\217\267", nullptr));
        editAccountButton->setText(QCoreApplication::translate("AdminMainWindow", "\347\274\226\350\276\221\350\264\246\345\217\267", nullptr));
        deleteAccountButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\240\351\231\244\350\264\246\345\217\267", nullptr));
        refreshAccountButton->setText(QCoreApplication::translate("AdminMainWindow", "\345\210\267\346\226\260", nullptr));
        label_5->setText(QCoreApplication::translate("AdminMainWindow", "\346\220\234\347\264\242\357\274\232", nullptr));
        accountSearchEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "\350\276\223\345\205\245\350\264\246\345\217\267\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMainWindow: public Ui_AdminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINWINDOW_H
