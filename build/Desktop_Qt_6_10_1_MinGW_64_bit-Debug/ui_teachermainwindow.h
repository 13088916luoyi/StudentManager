/********************************************************************************
** Form generated from reading UI file 'teachermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERMAINWINDOW_H
#define UI_TEACHERMAINWINDOW_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherMainWindow
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
    QLabel *teacherNoLabel;
    QLabel *label_2;
    QLabel *nameLabel;
    QLabel *label_3;
    QLabel *genderLabel;
    QLabel *label_4;
    QLabel *ageLabel;
    QLabel *label_5;
    QLabel *departmentLabel;
    QLabel *label_6;
    QLabel *titleLabelValue;
    QLabel *label_7;
    QLabel *phoneLabel;
    QLabel *label_8;
    QLabel *emailLabel;
    QSpacerItem *verticalSpacer;
    QWidget *coursesPage;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_courses;
    QLabel *coursesTitleLabel;
    QSpacerItem *horizontalSpacer_courses;
    QPushButton *refreshCoursesButton;
    QTableWidget *courseTable;
    QWidget *courseStudentsPage;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *courseStudentsTitleLabel;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *editGradeButton;
    QPushButton *viewStatsButton;
    QPushButton *refreshCourseStudentsButton;
    QPushButton *backToCoursesButton;
    QTableWidget *courseStudentTable;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeacherMainWindow)
    {
        if (TeacherMainWindow->objectName().isEmpty())
            TeacherMainWindow->setObjectName("TeacherMainWindow");
        TeacherMainWindow->resize(1200, 750);
        centralwidget = new QWidget(TeacherMainWindow);
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

        teacherNoLabel = new QLabel(groupBox);
        teacherNoLabel->setObjectName("teacherNoLabel");
        teacherNoLabel->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, teacherNoLabel);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameLabel);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        genderLabel = new QLabel(groupBox);
        genderLabel->setObjectName("genderLabel");
        genderLabel->setFont(font2);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderLabel);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        ageLabel = new QLabel(groupBox);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setFont(font2);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ageLabel);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        departmentLabel = new QLabel(groupBox);
        departmentLabel->setObjectName("departmentLabel");
        departmentLabel->setFont(font2);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departmentLabel);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        titleLabelValue = new QLabel(groupBox);
        titleLabelValue->setObjectName("titleLabelValue");
        titleLabelValue->setFont(font2);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, titleLabelValue);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        phoneLabel = new QLabel(groupBox);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setFont(font2);

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, phoneLabel);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_8);

        emailLabel = new QLabel(groupBox);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setFont(font2);

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, emailLabel);


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
        horizontalLayout_courses = new QHBoxLayout();
        horizontalLayout_courses->setObjectName("horizontalLayout_courses");
        coursesTitleLabel = new QLabel(coursesPage);
        coursesTitleLabel->setObjectName("coursesTitleLabel");
        coursesTitleLabel->setFont(font);

        horizontalLayout_courses->addWidget(coursesTitleLabel);

        horizontalSpacer_courses = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_courses->addItem(horizontalSpacer_courses);

        refreshCoursesButton = new QPushButton(coursesPage);
        refreshCoursesButton->setObjectName("refreshCoursesButton");
        refreshCoursesButton->setMinimumSize(QSize(80, 32));
        refreshCoursesButton->setFont(font1);

        horizontalLayout_courses->addWidget(refreshCoursesButton);


        verticalLayout_3->addLayout(horizontalLayout_courses);

        courseTable = new QTableWidget(coursesPage);
        courseTable->setObjectName("courseTable");
        QFont font3;
        font3.setPointSize(12);
        courseTable->setFont(font3);
        courseTable->setSelectionMode(QAbstractItemView::SingleSelection);
        courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        courseTable->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(courseTable);

        stackedWidget->addWidget(coursesPage);
        courseStudentsPage = new QWidget();
        courseStudentsPage->setObjectName("courseStudentsPage");
        verticalLayout_6 = new QVBoxLayout(courseStudentsPage);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        courseStudentsTitleLabel = new QLabel(courseStudentsPage);
        courseStudentsTitleLabel->setObjectName("courseStudentsTitleLabel");
        courseStudentsTitleLabel->setFont(font);

        horizontalLayout_6->addWidget(courseStudentsTitleLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        editGradeButton = new QPushButton(courseStudentsPage);
        editGradeButton->setObjectName("editGradeButton");
        editGradeButton->setMinimumSize(QSize(80, 32));
        editGradeButton->setFont(font1);

        horizontalLayout_6->addWidget(editGradeButton);

        viewStatsButton = new QPushButton(courseStudentsPage);
        viewStatsButton->setObjectName("viewStatsButton");
        viewStatsButton->setMinimumSize(QSize(80, 32));
        viewStatsButton->setFont(font1);

        horizontalLayout_6->addWidget(viewStatsButton);

        refreshCourseStudentsButton = new QPushButton(courseStudentsPage);
        refreshCourseStudentsButton->setObjectName("refreshCourseStudentsButton");
        refreshCourseStudentsButton->setMinimumSize(QSize(80, 32));
        refreshCourseStudentsButton->setFont(font1);

        horizontalLayout_6->addWidget(refreshCourseStudentsButton);

        backToCoursesButton = new QPushButton(courseStudentsPage);
        backToCoursesButton->setObjectName("backToCoursesButton");
        backToCoursesButton->setMinimumSize(QSize(100, 32));
        backToCoursesButton->setFont(font1);

        horizontalLayout_6->addWidget(backToCoursesButton);


        verticalLayout_6->addLayout(horizontalLayout_6);

        courseStudentTable = new QTableWidget(courseStudentsPage);
        courseStudentTable->setObjectName("courseStudentTable");
        courseStudentTable->setFont(font3);
        courseStudentTable->setSelectionMode(QAbstractItemView::SingleSelection);
        courseStudentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        courseStudentTable->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(courseStudentTable);

        stackedWidget->addWidget(courseStudentsPage);

        horizontalLayout_main->addWidget(stackedWidget);

        TeacherMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TeacherMainWindow);
        statusbar->setObjectName("statusbar");
        TeacherMainWindow->setStatusBar(statusbar);

        retranslateUi(TeacherMainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TeacherMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherMainWindow)
    {
        TeacherMainWindow->setWindowTitle(QCoreApplication::translate("TeacherMainWindow", "\346\225\231\345\270\210\344\270\273\347\252\227\345\217\243", nullptr));
        titleLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\346\225\231\345\270\210\345\267\245\344\275\234\345\217\260", nullptr));
        navProfileButton->setText(QCoreApplication::translate("TeacherMainWindow", "  \344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        navCoursesButton->setText(QCoreApplication::translate("TeacherMainWindow", "  \346\210\221\347\232\204\350\257\276\347\250\213", nullptr));
        logoutButton->setText(QCoreApplication::translate("TeacherMainWindow", "  \351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        profileTitleLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        editProfileButton->setText(QCoreApplication::translate("TeacherMainWindow", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TeacherMainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("TeacherMainWindow", "\345\267\245\345\217\267\357\274\232", nullptr));
        teacherNoLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherMainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_3->setText(QCoreApplication::translate("TeacherMainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_4->setText(QCoreApplication::translate("TeacherMainWindow", "\345\271\264\351\276\204\357\274\232", nullptr));
        ageLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherMainWindow", "\351\231\242\347\263\273\357\274\232", nullptr));
        departmentLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_6->setText(QCoreApplication::translate("TeacherMainWindow", "\350\201\214\347\247\260\357\274\232", nullptr));
        titleLabelValue->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_7->setText(QCoreApplication::translate("TeacherMainWindow", "\347\224\265\350\257\235\357\274\232", nullptr));
        phoneLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        label_8->setText(QCoreApplication::translate("TeacherMainWindow", "\351\202\256\347\256\261\357\274\232", nullptr));
        emailLabel->setText(QCoreApplication::translate("TeacherMainWindow", "-", nullptr));
        coursesTitleLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\346\210\221\347\232\204\350\257\276\347\250\213 (\345\217\214\345\207\273\346\237\245\347\234\213\350\257\276\347\250\213\345\255\246\347\224\237)", nullptr));
        refreshCoursesButton->setText(QCoreApplication::translate("TeacherMainWindow", "\345\210\267\346\226\260", nullptr));
        courseStudentsTitleLabel->setText(QCoreApplication::translate("TeacherMainWindow", "\350\257\276\347\250\213\345\255\246\347\224\237\345\210\227\350\241\250", nullptr));
        editGradeButton->setText(QCoreApplication::translate("TeacherMainWindow", "\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        viewStatsButton->setText(QCoreApplication::translate("TeacherMainWindow", "\346\237\245\347\234\213\347\273\237\350\256\241", nullptr));
        refreshCourseStudentsButton->setText(QCoreApplication::translate("TeacherMainWindow", "\345\210\267\346\226\260", nullptr));
        backToCoursesButton->setText(QCoreApplication::translate("TeacherMainWindow", "\350\277\224\345\233\236\350\257\276\347\250\213\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherMainWindow: public Ui_TeacherMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERMAINWINDOW_H
