/********************************************************************************
** Form generated from reading UI file 'teacherprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERPROFILEDIALOG_H
#define UI_TEACHERPROFILEDIALOG_H

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

class Ui_TeacherProfileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_teacherNo;
    QLabel *teacherNoLabel;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QLabel *label_gender;
    QComboBox *genderCombo;
    QLabel *label_age;
    QSpinBox *ageSpinBox;
    QLabel *label_department;
    QLineEdit *departmentEdit;
    QLabel *label_title;
    QLineEdit *titleEdit;
    QLabel *label_phone;
    QLineEdit *phoneEdit;
    QLabel *label_email;
    QLineEdit *emailEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherProfileDialog)
    {
        if (TeacherProfileDialog->objectName().isEmpty())
            TeacherProfileDialog->setObjectName("TeacherProfileDialog");
        TeacherProfileDialog->resize(450, 420);
        verticalLayout = new QVBoxLayout(TeacherProfileDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        groupBox = new QGroupBox(TeacherProfileDialog);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        label_teacherNo = new QLabel(groupBox);
        label_teacherNo->setObjectName("label_teacherNo");
        label_teacherNo->setFont(font);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_teacherNo);

        teacherNoLabel = new QLabel(groupBox);
        teacherNoLabel->setObjectName("teacherNoLabel");
        teacherNoLabel->setFont(font);
        teacherNoLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, teacherNoLabel);

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
        ageSpinBox->setMinimum(18);
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

        label_title = new QLabel(groupBox);
        label_title->setObjectName("label_title");
        label_title->setFont(font);

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_title);

        titleEdit = new QLineEdit(groupBox);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setFont(font);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, titleEdit);

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

        buttonBox = new QDialogButtonBox(TeacherProfileDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherProfileDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TeacherProfileDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TeacherProfileDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TeacherProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherProfileDialog)
    {
        TeacherProfileDialog->setWindowTitle(QCoreApplication::translate("TeacherProfileDialog", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TeacherProfileDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_teacherNo->setText(QCoreApplication::translate("TeacherProfileDialog", "\345\267\245\345\217\267\357\274\232", nullptr));
        teacherNoLabel->setText(QCoreApplication::translate("TeacherProfileDialog", "-", nullptr));
        label_name->setText(QCoreApplication::translate("TeacherProfileDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_gender->setText(QCoreApplication::translate("TeacherProfileDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("TeacherProfileDialog", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("TeacherProfileDialog", "\345\245\263", nullptr));

        label_age->setText(QCoreApplication::translate("TeacherProfileDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_department->setText(QCoreApplication::translate("TeacherProfileDialog", "\351\231\242\347\263\273\357\274\232", nullptr));
        label_title->setText(QCoreApplication::translate("TeacherProfileDialog", "\350\201\214\347\247\260\357\274\232", nullptr));
        label_phone->setText(QCoreApplication::translate("TeacherProfileDialog", "\347\224\265\350\257\235\357\274\232", nullptr));
        label_email->setText(QCoreApplication::translate("TeacherProfileDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherProfileDialog: public Ui_TeacherProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERPROFILEDIALOG_H
