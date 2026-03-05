/********************************************************************************
** Form generated from reading UI file 'teacherdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERDIALOG_H
#define UI_TEACHERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *teacherNoEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *coursesLabel;
    QHBoxLayout *coursesLayout;
    QLabel *coursesDisplayLabel;
    QPushButton *selectCoursesButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherDialog)
    {
        if (TeacherDialog->objectName().isEmpty())
            TeacherDialog->setObjectName("TeacherDialog");
        TeacherDialog->resize(450, 280);
        TeacherDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QLabel {\n"
"    font-size: 13px;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 13px;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4a90d9;\n"
"}\n"
"QPushButton {\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton[text=\"\347\241\256\345\256\232\"], QPushButton[text=\"OK\"] {\n"
"    background-color: #4a90d9;\n"
"    color: white;\n"
"}\n"
"QPushButton[text=\"\347\241\256\345\256\232\"]:hover, QPushButton[text=\"OK\"]:hover {\n"
"    background-color: #3a7bc8;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"], QPushButton[text=\"Cancel\"] {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]"
                        ":hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"QPushButton#selectCoursesButton {\n"
"    background-color: #5cb85c;\n"
"    color: white;\n"
"    padding: 8px 15px;\n"
"}\n"
"QPushButton#selectCoursesButton:hover {\n"
"    background-color: #4cae4c;\n"
"}\n"
"QLabel#coursesDisplayLabel {\n"
"    font-size: 12px;\n"
"    color: #666666;\n"
"    font-weight: normal;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    min-height: 30px;\n"
"}"));
        verticalLayout = new QVBoxLayout(TeacherDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(TeacherDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        label = new QLabel(TeacherDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        teacherNoEdit = new QLineEdit(TeacherDialog);
        teacherNoEdit->setObjectName("teacherNoEdit");
        teacherNoEdit->setMinimumSize(QSize(300, 35));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, teacherNoEdit);

        label_2 = new QLabel(TeacherDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameEdit = new QLineEdit(TeacherDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setMinimumSize(QSize(300, 35));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        coursesLabel = new QLabel(TeacherDialog);
        coursesLabel->setObjectName("coursesLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, coursesLabel);

        coursesLayout = new QHBoxLayout();
        coursesLayout->setSpacing(10);
        coursesLayout->setObjectName("coursesLayout");
        coursesDisplayLabel = new QLabel(TeacherDialog);
        coursesDisplayLabel->setObjectName("coursesDisplayLabel");
        coursesDisplayLabel->setWordWrap(true);

        coursesLayout->addWidget(coursesDisplayLabel);

        selectCoursesButton = new QPushButton(TeacherDialog);
        selectCoursesButton->setObjectName("selectCoursesButton");

        coursesLayout->addWidget(selectCoursesButton);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, coursesLayout);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(TeacherDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TeacherDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TeacherDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TeacherDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherDialog)
    {
        TeacherDialog->setWindowTitle(QCoreApplication::translate("TeacherDialog", "\346\225\231\345\270\210\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("TeacherDialog", "\346\225\231\345\270\210\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("TeacherDialog", "\345\267\245\345\217\267\357\274\232", nullptr));
        teacherNoEdit->setPlaceholderText(QCoreApplication::translate("TeacherDialog", "\350\257\267\350\276\223\345\205\245\345\267\245\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("TeacherDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        coursesLabel->setText(QCoreApplication::translate("TeacherDialog", "\346\225\231\346\216\210\350\257\276\347\250\213\357\274\232", nullptr));
        coursesDisplayLabel->setText(QCoreApplication::translate("TeacherDialog", "\346\234\252\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
        selectCoursesButton->setText(QCoreApplication::translate("TeacherDialog", "\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherDialog: public Ui_TeacherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERDIALOG_H
