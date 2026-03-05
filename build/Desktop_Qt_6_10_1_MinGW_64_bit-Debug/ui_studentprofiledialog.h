/********************************************************************************
** Form generated from reading UI file 'studentprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPROFILEDIALOG_H
#define UI_STUDENTPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentProfileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_studentNo;
    QLabel *studentNoLabel;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_gender;
    QComboBox *genderCombo;
    QLabel *label_age;
    QSpinBox *ageSpinBox;
    QLabel *label_department;
    QLineEdit *departmentEdit;
    QLabel *label_class;
    QLineEdit *classEdit;
    QLabel *label_phone;
    QLineEdit *phoneEdit;
    QLabel *label_email;
    QLineEdit *emailEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StudentProfileDialog)
    {
        if (StudentProfileDialog->objectName().isEmpty())
            StudentProfileDialog->setObjectName("StudentProfileDialog");
        StudentProfileDialog->resize(450, 450);
        verticalLayout = new QVBoxLayout(StudentProfileDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        groupBox = new QGroupBox(StudentProfileDialog);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        label_studentNo = new QLabel(groupBox);
        label_studentNo->setObjectName("label_studentNo");
        label_studentNo->setFont(font);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_studentNo);

        studentNoLabel = new QLabel(groupBox);
        studentNoLabel->setObjectName("studentNoLabel");
        studentNoLabel->setFont(font);
        studentNoLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentNoLabel);

        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");
        label_name->setFont(font);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_name);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_gender = new QLabel(groupBox);
        label_gender->setObjectName("label_gender");
        label_gender->setFont(font);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_gender);

        genderCombo = new QComboBox(groupBox);
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->setObjectName("genderCombo");
        genderCombo->setFont(font);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderCombo);

        label_age = new QLabel(groupBox);
        label_age->setObjectName("label_age");
        label_age->setFont(font);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_age);

        ageSpinBox = new QSpinBox(groupBox);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setFont(font);
        ageSpinBox->setMinimum(16);
        ageSpinBox->setMaximum(100);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ageSpinBox);

        label_department = new QLabel(groupBox);
        label_department->setObjectName("label_department");
        label_department->setFont(font);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_department);

        departmentEdit = new QLineEdit(groupBox);
        departmentEdit->setObjectName("departmentEdit");
        departmentEdit->setFont(font);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departmentEdit);

        label_class = new QLabel(groupBox);
        label_class->setObjectName("label_class");
        label_class->setFont(font);

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_class);

        classEdit = new QLineEdit(groupBox);
        classEdit->setObjectName("classEdit");
        classEdit->setFont(font);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, classEdit);

        label_phone = new QLabel(groupBox);
        label_phone->setObjectName("label_phone");
        label_phone->setFont(font);

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_phone);

        phoneEdit = new QLineEdit(groupBox);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setFont(font);

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, phoneEdit);

        label_email = new QLabel(groupBox);
        label_email->setObjectName("label_email");
        label_email->setFont(font);

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_email);

        emailEdit = new QLineEdit(groupBox);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setFont(font);

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(StudentProfileDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StudentProfileDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StudentProfileDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StudentProfileDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StudentProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentProfileDialog)
    {
        StudentProfileDialog->setWindowTitle(QCoreApplication::translate("StudentProfileDialog", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StudentProfileDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_studentNo->setText(QCoreApplication::translate("StudentProfileDialog", "\345\255\246\345\217\267\357\274\232", nullptr));
        studentNoLabel->setText(QCoreApplication::translate("StudentProfileDialog", "-", nullptr));
        label_name->setText(QCoreApplication::translate("StudentProfileDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_gender->setText(QCoreApplication::translate("StudentProfileDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("StudentProfileDialog", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("StudentProfileDialog", "\345\245\263", nullptr));

        label_age->setText(QCoreApplication::translate("StudentProfileDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_department->setText(QCoreApplication::translate("StudentProfileDialog", "\351\231\242\347\263\273\357\274\232", nullptr));
        label_class->setText(QCoreApplication::translate("StudentProfileDialog", "\347\217\255\347\272\247\357\274\232", nullptr));
        label_phone->setText(QCoreApplication::translate("StudentProfileDialog", "\347\224\265\350\257\235\357\274\232", nullptr));
        label_email->setText(QCoreApplication::translate("StudentProfileDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentProfileDialog: public Ui_StudentProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPROFILEDIALOG_H
