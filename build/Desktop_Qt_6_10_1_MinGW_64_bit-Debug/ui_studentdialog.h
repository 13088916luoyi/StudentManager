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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *studentNoEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QComboBox *genderComboBox;
    QLabel *label_4;
    QSpinBox *ageSpinBox;
    QLabel *label_5;
    QComboBox *departmentComboBox;
    QLabel *label_6;
    QComboBox *classComboBox;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QLabel *label_8;
    QLineEdit *emailEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName("StudentDialog");
        StudentDialog->resize(400, 400);
        verticalLayout = new QVBoxLayout(StudentDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(StudentDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        studentNoEdit = new QLineEdit(StudentDialog);
        studentNoEdit->setObjectName("studentNoEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentNoEdit);

        label_2 = new QLabel(StudentDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameEdit = new QLineEdit(StudentDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_3 = new QLabel(StudentDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        genderComboBox = new QComboBox(StudentDialog);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderComboBox);

        label_4 = new QLabel(StudentDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        ageSpinBox = new QSpinBox(StudentDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setMinimum(1);
        ageSpinBox->setMaximum(100);
        ageSpinBox->setValue(20);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ageSpinBox);

        label_5 = new QLabel(StudentDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        departmentComboBox = new QComboBox(StudentDialog);
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->setObjectName("departmentComboBox");
        departmentComboBox->setEditable(true);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departmentComboBox);

        label_6 = new QLabel(StudentDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        classComboBox = new QComboBox(StudentDialog);
        classComboBox->addItem(QString());
        classComboBox->addItem(QString());
        classComboBox->addItem(QString());
        classComboBox->addItem(QString());
        classComboBox->setObjectName("classComboBox");
        classComboBox->setEditable(true);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, classComboBox);

        label_7 = new QLabel(StudentDialog);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        phoneEdit = new QLineEdit(StudentDialog);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, phoneEdit);

        label_8 = new QLabel(StudentDialog);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_8);

        emailEdit = new QLineEdit(StudentDialog);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(StudentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StudentDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StudentDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StudentDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QCoreApplication::translate("StudentDialog", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("StudentDialog", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("StudentDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("StudentDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("StudentDialog", "\347\224\267", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("StudentDialog", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("StudentDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("StudentDialog", "\351\231\242\347\263\273\357\274\232", nullptr));
        departmentComboBox->setItemText(0, QCoreApplication::translate("StudentDialog", "\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(1, QCoreApplication::translate("StudentDialog", "\346\225\260\345\255\246\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(2, QCoreApplication::translate("StudentDialog", "\347\211\251\347\220\206\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(3, QCoreApplication::translate("StudentDialog", "\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(4, QCoreApplication::translate("StudentDialog", "\347\273\217\346\265\216\347\256\241\347\220\206\345\255\246\351\231\242", nullptr));

        label_6->setText(QCoreApplication::translate("StudentDialog", "\347\217\255\347\272\247\357\274\232", nullptr));
        classComboBox->setItemText(0, QCoreApplication::translate("StudentDialog", "\350\275\257\344\273\2661\347\217\255", nullptr));
        classComboBox->setItemText(1, QCoreApplication::translate("StudentDialog", "\350\275\257\344\273\2662\347\217\255", nullptr));
        classComboBox->setItemText(2, QCoreApplication::translate("StudentDialog", "\350\256\241\347\256\227\346\234\2721\347\217\255", nullptr));
        classComboBox->setItemText(3, QCoreApplication::translate("StudentDialog", "\350\256\241\347\256\227\346\234\2722\347\217\255", nullptr));

        label_7->setText(QCoreApplication::translate("StudentDialog", "\347\224\265\350\257\235\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("StudentDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
