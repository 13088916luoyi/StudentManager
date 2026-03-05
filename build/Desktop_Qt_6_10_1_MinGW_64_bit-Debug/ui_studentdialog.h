/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *studentNoEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_5;
    QLineEdit *departmentEdit;
    QLabel *label_6;
    QLineEdit *classEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName("StudentDialog");
        StudentDialog->resize(450, 280);
        StudentDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"}"));
        verticalLayout = new QVBoxLayout(StudentDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(StudentDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(StudentDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        studentNoEdit = new QLineEdit(StudentDialog);
        studentNoEdit->setObjectName("studentNoEdit");
        studentNoEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentNoEdit);

        label_2 = new QLabel(StudentDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameEdit = new QLineEdit(StudentDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_5 = new QLabel(StudentDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_5);

        departmentEdit = new QLineEdit(StudentDialog);
        departmentEdit->setObjectName("departmentEdit");
        departmentEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, departmentEdit);

        label_6 = new QLabel(StudentDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_6);

        classEdit = new QLineEdit(StudentDialog);
        classEdit->setObjectName("classEdit");
        classEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, classEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(StudentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StudentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StudentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StudentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QCoreApplication::translate("StudentDialog", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("StudentDialog", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("StudentDialog", "\345\255\246\345\217\267\357\274\232", nullptr));
        studentNoEdit->setPlaceholderText(QCoreApplication::translate("StudentDialog", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("StudentDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("StudentDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("StudentDialog", "\344\270\223\344\270\232\357\274\232", nullptr));
        departmentEdit->setPlaceholderText(QCoreApplication::translate("StudentDialog", "\350\257\267\350\276\223\345\205\245\344\270\223\344\270\232", nullptr));
        label_6->setText(QCoreApplication::translate("StudentDialog", "\347\217\255\347\272\247\357\274\232", nullptr));
        classEdit->setPlaceholderText(QCoreApplication::translate("StudentDialog", "\350\257\267\350\276\223\345\205\245\347\217\255\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
