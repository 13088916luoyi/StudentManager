/********************************************************************************
** Form generated from reading UI file 'studentmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMAINWINDOW_H
#define UI_STUDENTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentMainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QWidget *navPanel;
    QVBoxLayout *verticalLayout_nav;
    QLabel *titleLabel;
    QFrame *line_1;
    QPushButton *navProfileButton;
    QPushButton *navCoursesButton;
    QPushButton *navGradesButton;
    QSpacerItem *verticalSpacer_nav;
    QFrame *line_2;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *profilePage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_profile;
    QLabel *profileTitleLabel;
    QSpacerItem *horizontalSpacer_profile;
    QPushButton *editProfileButton;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *studentNoLabel;
    QLabel *label_2;
    QLabel *nameLabel;
    QLabel *label_class;
    QLabel *classLabel;
    QLabel *label_major;
    QLabel *majorLabel;
    QSpacerItem *verticalSpacer;
    QWidget *coursesPage;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *courseTabWidget;
    QWidget *myCoursesTab;
    QVBoxLayout *verticalLayout_myCourses;
    QHBoxLayout *horizontalLayout_myCourses;
    QLabel *myCoursesLabel;
    QSpacerItem *horizontalSpacer_myCourses;
    QPushButton *dropCourseButton;
    QPushButton *refreshMyCoursesButton;
    QTableWidget *myCourseTable;
    QWidget *selectCourseTab;
    QVBoxLayout *verticalLayout_selectCourse;
    QHBoxLayout *horizontalLayout_selectCourse;
    QLabel *selectCourseLabel;
    QSpacerItem *horizontalSpacer_selectCourse;
    QPushButton *selectCourseButton;
    QPushButton *refreshSelectCourseButton;
    QTableWidget *availableCourseTable;
    QWidget *gradesPage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_grades;
    QLabel *gradesTitleLabel;
    QSpacerItem *horizontalSpacer_grades;
    QPushButton *refreshGradesButton;
    QTableWidget *gradeTable;
    QGroupBox *statsGroupBox;
    QHBoxLayout *horizontalLayout_stats;
    QLabel *avgLabel;
    QLabel *maxLabel;
    QLabel *minLabel;
    QLabel *countLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentMainWindow)
    {
        if (StudentMainWindow->objectName().isEmpty())
            StudentMainWindow->setObjectName("StudentMainWindow");
        StudentMainWindow->resize(1200, 750);
        centralwidget = new QWidget(StudentMainWindow);
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

        navProfileButton = new QPushButton(navPanel);
        navProfileButton->setObjectName("navProfileButton");
        navProfileButton->setMinimumSize(QSize(0, 45));
        navProfileButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navProfileButton->setCheckable(true);
        navProfileButton->setChecked(true);

        verticalLayout_nav->addWidget(navProfileButton);

        navCoursesButton = new QPushButton(navPanel);
        navCoursesButton->setObjectName("navCoursesButton");
        navCoursesButton->setMinimumSize(QSize(0, 45));
        navCoursesButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navCoursesButton->setCheckable(true);

        verticalLayout_nav->addWidget(navCoursesButton);

        navGradesButton = new QPushButton(navPanel);
        navGradesButton->setObjectName("navGradesButton");
        navGradesButton->setMinimumSize(QSize(0, 45));
        navGradesButton->setStyleSheet(QString::fromUtf8("QPushButton { color: white; font-size: 14px; text-align: left; padding-left: 20px; border: none; background-color: transparent; }\n"
"QPushButton:hover { background-color: #34495e; }\n"
"QPushButton:checked { background-color: #3498db; }"));
        navGradesButton->setCheckable(true);

        verticalLayout_nav->addWidget(navGradesButton);

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
        profilePage = new QWidget();
        profilePage->setObjectName("profilePage");
        verticalLayout_2 = new QVBoxLayout(profilePage);
        verticalLayout_2->setSpacing(8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_profile = new QHBoxLayout();
        horizontalLayout_profile->setObjectName("horizontalLayout_profile");
        profileTitleLabel = new QLabel(profilePage);
        profileTitleLabel->setObjectName("profileTitleLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        profileTitleLabel->setFont(font);

        horizontalLayout_profile->addWidget(profileTitleLabel);

        horizontalSpacer_profile = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_profile->addItem(horizontalSpacer_profile);

        editProfileButton = new QPushButton(profilePage);
        editProfileButton->setObjectName("editProfileButton");
        editProfileButton->setMinimumSize(QSize(100, 32));
        QFont font1;
        font1.setPointSize(10);
        editProfileButton->setFont(font1);

        horizontalLayout_profile->addWidget(editProfileButton);


        verticalLayout_2->addLayout(horizontalLayout_profile);

        groupBox = new QGroupBox(profilePage);
        groupBox->setObjectName("groupBox");
        QFont font2;
        font2.setPointSize(11);
        groupBox->setFont(font2);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(15);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        studentNoLabel = new QLabel(groupBox);
        studentNoLabel->setObjectName("studentNoLabel");
        studentNoLabel->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentNoLabel);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameLabel);

        label_class = new QLabel(groupBox);
        label_class->setObjectName("label_class");
        label_class->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_class);

        classLabel = new QLabel(groupBox);
        classLabel->setObjectName("classLabel");
        classLabel->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, classLabel);

        label_major = new QLabel(groupBox);
        label_major->setObjectName("label_major");
        label_major->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_major);

        majorLabel = new QLabel(groupBox);
        majorLabel->setObjectName("majorLabel");
        majorLabel->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, majorLabel);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        stackedWidget->addWidget(profilePage);
        coursesPage = new QWidget();
        coursesPage->setObjectName("coursesPage");
        verticalLayout_3 = new QVBoxLayout(coursesPage);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(20, 20, 20, 20);
        courseTabWidget = new QTabWidget(coursesPage);
        courseTabWidget->setObjectName("courseTabWidget");
        courseTabWidget->setFont(font2);
        myCoursesTab = new QWidget();
        myCoursesTab->setObjectName("myCoursesTab");
        verticalLayout_myCourses = new QVBoxLayout(myCoursesTab);
        verticalLayout_myCourses->setSpacing(10);
        verticalLayout_myCourses->setObjectName("verticalLayout_myCourses");
        verticalLayout_myCourses->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_myCourses = new QHBoxLayout();
        horizontalLayout_myCourses->setObjectName("horizontalLayout_myCourses");
        myCoursesLabel = new QLabel(myCoursesTab);
        myCoursesLabel->setObjectName("myCoursesLabel");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        myCoursesLabel->setFont(font3);

        horizontalLayout_myCourses->addWidget(myCoursesLabel);

        horizontalSpacer_myCourses = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_myCourses->addItem(horizontalSpacer_myCourses);

        dropCourseButton = new QPushButton(myCoursesTab);
        dropCourseButton->setObjectName("dropCourseButton");
        dropCourseButton->setMinimumSize(QSize(80, 32));
        dropCourseButton->setFont(font1);

        horizontalLayout_myCourses->addWidget(dropCourseButton);

        refreshMyCoursesButton = new QPushButton(myCoursesTab);
        refreshMyCoursesButton->setObjectName("refreshMyCoursesButton");
        refreshMyCoursesButton->setMinimumSize(QSize(80, 32));
        refreshMyCoursesButton->setFont(font1);

        horizontalLayout_myCourses->addWidget(refreshMyCoursesButton);


        verticalLayout_myCourses->addLayout(horizontalLayout_myCourses);

        myCourseTable = new QTableWidget(myCoursesTab);
        myCourseTable->setObjectName("myCourseTable");
        QFont font4;
        font4.setPointSize(12);
        myCourseTable->setFont(font4);
        myCourseTable->setSelectionMode(QAbstractItemView::SingleSelection);
        myCourseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        myCourseTable->setAlternatingRowColors(true);

        verticalLayout_myCourses->addWidget(myCourseTable);

        courseTabWidget->addTab(myCoursesTab, QString());
        selectCourseTab = new QWidget();
        selectCourseTab->setObjectName("selectCourseTab");
        verticalLayout_selectCourse = new QVBoxLayout(selectCourseTab);
        verticalLayout_selectCourse->setSpacing(10);
        verticalLayout_selectCourse->setObjectName("verticalLayout_selectCourse");
        verticalLayout_selectCourse->setContentsMargins(10, 10, 10, 10);
        horizontalLayout_selectCourse = new QHBoxLayout();
        horizontalLayout_selectCourse->setObjectName("horizontalLayout_selectCourse");
        selectCourseLabel = new QLabel(selectCourseTab);
        selectCourseLabel->setObjectName("selectCourseLabel");
        selectCourseLabel->setFont(font3);

        horizontalLayout_selectCourse->addWidget(selectCourseLabel);

        horizontalSpacer_selectCourse = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_selectCourse->addItem(horizontalSpacer_selectCourse);

        selectCourseButton = new QPushButton(selectCourseTab);
        selectCourseButton->setObjectName("selectCourseButton");
        selectCourseButton->setMinimumSize(QSize(80, 32));
        selectCourseButton->setFont(font1);

        horizontalLayout_selectCourse->addWidget(selectCourseButton);

        refreshSelectCourseButton = new QPushButton(selectCourseTab);
        refreshSelectCourseButton->setObjectName("refreshSelectCourseButton");
        refreshSelectCourseButton->setMinimumSize(QSize(80, 32));
        refreshSelectCourseButton->setFont(font1);

        horizontalLayout_selectCourse->addWidget(refreshSelectCourseButton);


        verticalLayout_selectCourse->addLayout(horizontalLayout_selectCourse);

        availableCourseTable = new QTableWidget(selectCourseTab);
        availableCourseTable->setObjectName("availableCourseTable");
        availableCourseTable->setFont(font4);
        availableCourseTable->setSelectionMode(QAbstractItemView::SingleSelection);
        availableCourseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        availableCourseTable->setAlternatingRowColors(true);

        verticalLayout_selectCourse->addWidget(availableCourseTable);

        courseTabWidget->addTab(selectCourseTab, QString());

        verticalLayout_3->addWidget(courseTabWidget);

        stackedWidget->addWidget(coursesPage);
        gradesPage = new QWidget();
        gradesPage->setObjectName("gradesPage");
        verticalLayout_4 = new QVBoxLayout(gradesPage);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_grades = new QHBoxLayout();
        horizontalLayout_grades->setObjectName("horizontalLayout_grades");
        gradesTitleLabel = new QLabel(gradesPage);
        gradesTitleLabel->setObjectName("gradesTitleLabel");
        gradesTitleLabel->setFont(font);

        horizontalLayout_grades->addWidget(gradesTitleLabel);

        horizontalSpacer_grades = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_grades->addItem(horizontalSpacer_grades);

        refreshGradesButton = new QPushButton(gradesPage);
        refreshGradesButton->setObjectName("refreshGradesButton");
        refreshGradesButton->setMinimumSize(QSize(80, 32));
        refreshGradesButton->setFont(font1);

        horizontalLayout_grades->addWidget(refreshGradesButton);


        verticalLayout_4->addLayout(horizontalLayout_grades);

        gradeTable = new QTableWidget(gradesPage);
        gradeTable->setObjectName("gradeTable");
        gradeTable->setFont(font4);
        gradeTable->setSelectionMode(QAbstractItemView::SingleSelection);
        gradeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        gradeTable->setAlternatingRowColors(true);

        verticalLayout_4->addWidget(gradeTable);

        statsGroupBox = new QGroupBox(gradesPage);
        statsGroupBox->setObjectName("statsGroupBox");
        statsGroupBox->setFont(font2);
        horizontalLayout_stats = new QHBoxLayout(statsGroupBox);
        horizontalLayout_stats->setSpacing(30);
        horizontalLayout_stats->setObjectName("horizontalLayout_stats");
        avgLabel = new QLabel(statsGroupBox);
        avgLabel->setObjectName("avgLabel");
        avgLabel->setFont(font2);

        horizontalLayout_stats->addWidget(avgLabel);

        maxLabel = new QLabel(statsGroupBox);
        maxLabel->setObjectName("maxLabel");
        maxLabel->setFont(font2);

        horizontalLayout_stats->addWidget(maxLabel);

        minLabel = new QLabel(statsGroupBox);
        minLabel->setObjectName("minLabel");
        minLabel->setFont(font2);

        horizontalLayout_stats->addWidget(minLabel);

        countLabel = new QLabel(statsGroupBox);
        countLabel->setObjectName("countLabel");
        countLabel->setFont(font2);

        horizontalLayout_stats->addWidget(countLabel);


        verticalLayout_4->addWidget(statsGroupBox);

        stackedWidget->addWidget(gradesPage);

        horizontalLayout_main->addWidget(stackedWidget);

        StudentMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StudentMainWindow);
        statusbar->setObjectName("statusbar");
        StudentMainWindow->setStatusBar(statusbar);

        retranslateUi(StudentMainWindow);

        stackedWidget->setCurrentIndex(0);
        courseTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StudentMainWindow)
    {
        StudentMainWindow->setWindowTitle(QCoreApplication::translate("StudentMainWindow", "\345\255\246\347\224\237\344\270\273\347\252\227\345\217\243", nullptr));
        titleLabel->setText(QCoreApplication::translate("StudentMainWindow", "\345\255\246\347\224\237\345\267\245\344\275\234\345\217\260", nullptr));
        navProfileButton->setText(QCoreApplication::translate("StudentMainWindow", "  \344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        navCoursesButton->setText(QCoreApplication::translate("StudentMainWindow", "  \346\210\221\347\232\204\350\257\276\347\250\213", nullptr));
        navGradesButton->setText(QCoreApplication::translate("StudentMainWindow", "  \346\210\221\347\232\204\346\210\220\347\273\251", nullptr));
        logoutButton->setText(QCoreApplication::translate("StudentMainWindow", "  \351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        profileTitleLabel->setText(QCoreApplication::translate("StudentMainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        editProfileButton->setText(QCoreApplication::translate("StudentMainWindow", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StudentMainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("StudentMainWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        studentNoLabel->setText(QCoreApplication::translate("StudentMainWindow", "-", nullptr));
        label_2->setText(QCoreApplication::translate("StudentMainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameLabel->setText(QCoreApplication::translate("StudentMainWindow", "-", nullptr));
        label_class->setText(QCoreApplication::translate("StudentMainWindow", "\347\217\255\347\272\247\357\274\232", nullptr));
        classLabel->setText(QCoreApplication::translate("StudentMainWindow", "-", nullptr));
        label_major->setText(QCoreApplication::translate("StudentMainWindow", "\344\270\223\344\270\232\357\274\232", nullptr));
        majorLabel->setText(QCoreApplication::translate("StudentMainWindow", "-", nullptr));
        myCoursesLabel->setText(QCoreApplication::translate("StudentMainWindow", "\345\267\262\351\200\211\350\257\276\347\250\213\345\210\227\350\241\250", nullptr));
        dropCourseButton->setText(QCoreApplication::translate("StudentMainWindow", "\351\200\200\350\257\276", nullptr));
        refreshMyCoursesButton->setText(QCoreApplication::translate("StudentMainWindow", "\345\210\267\346\226\260", nullptr));
        courseTabWidget->setTabText(courseTabWidget->indexOf(myCoursesTab), QCoreApplication::translate("StudentMainWindow", "\345\267\262\351\200\211\350\257\276\347\250\213", nullptr));
        selectCourseLabel->setText(QCoreApplication::translate("StudentMainWindow", "\345\217\257\351\200\211\350\257\276\347\250\213\345\210\227\350\241\250", nullptr));
        selectCourseButton->setText(QCoreApplication::translate("StudentMainWindow", "\351\200\211\350\257\276", nullptr));
        refreshSelectCourseButton->setText(QCoreApplication::translate("StudentMainWindow", "\345\210\267\346\226\260", nullptr));
        courseTabWidget->setTabText(courseTabWidget->indexOf(selectCourseTab), QCoreApplication::translate("StudentMainWindow", "\351\200\211\350\257\276", nullptr));
        gradesTitleLabel->setText(QCoreApplication::translate("StudentMainWindow", "\346\210\221\347\232\204\346\210\220\347\273\251", nullptr));
        refreshGradesButton->setText(QCoreApplication::translate("StudentMainWindow", "\345\210\267\346\226\260", nullptr));
        statsGroupBox->setTitle(QCoreApplication::translate("StudentMainWindow", "\346\210\220\347\273\251\347\273\237\350\256\241", nullptr));
        avgLabel->setText(QCoreApplication::translate("StudentMainWindow", "\345\271\263\345\235\207\345\210\206\357\274\232-", nullptr));
        maxLabel->setText(QCoreApplication::translate("StudentMainWindow", "\346\234\200\351\253\230\345\210\206\357\274\232-", nullptr));
        minLabel->setText(QCoreApplication::translate("StudentMainWindow", "\346\234\200\344\275\216\345\210\206\357\274\232-", nullptr));
        countLabel->setText(QCoreApplication::translate("StudentMainWindow", "\350\257\276\347\250\213\346\225\260\357\274\232-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentMainWindow: public Ui_StudentMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMAINWINDOW_H
