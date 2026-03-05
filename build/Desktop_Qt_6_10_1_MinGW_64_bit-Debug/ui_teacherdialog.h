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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *teacherNoEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QComboBox *genderComboBox;
    QLabel *label_4;
    QSpinBox *ageSpinBox;
    QLabel *label_5;
    QComboBox *departmentComboBox;
    QLabel *label_6;
    QComboBox *titleComboBox;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QLabel *label_8;
    QLineEdit *emailEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherDialog)
    {
        if (TeacherDialog->objectName().isEmpty())
            TeacherDialog->setObjectName("TeacherDialog");
        TeacherDialog->resize(400, 420);
        verticalLayout = new QVBoxLayout(TeacherDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(TeacherDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        teacherNoEdit = new QLineEdit(TeacherDialog);
        teacherNoEdit->setObjectName("teacherNoEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, teacherNoEdit);

        label_2 = new QLabel(TeacherDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        nameEdit = new QLineEdit(TeacherDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);

        label_3 = new QLabel(TeacherDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        genderComboBox = new QComboBox(TeacherDialog);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, genderComboBox);

        label_4 = new QLabel(TeacherDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        ageSpinBox = new QSpinBox(TeacherDialog);
        ageSpinBox->setObjectName("ageSpinBox");
        ageSpinBox->setMinimum(1);
        ageSpinBox->setMaximum(100);
        ageSpinBox->setValue(35);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ageSpinBox);

        label_5 = new QLabel(TeacherDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        departmentComboBox = new QComboBox(TeacherDialog);
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->addItem(QString());
        departmentComboBox->setObjectName("departmentComboBox");
        departmentComboBox->setEditable(true);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, departmentComboBox);

        label_6 = new QLabel(TeacherDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        titleComboBox = new QComboBox(TeacherDialog);
        titleComboBox->addItem(QString());
        titleComboBox->addItem(QString());
        titleComboBox->addItem(QString());
        titleComboBox->addItem(QString());
        titleComboBox->setObjectName("titleComboBox");
        titleComboBox->setEditable(true);

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, titleComboBox);

        label_7 = new QLabel(TeacherDialog);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, label_7);

        phoneEdit = new QLineEdit(TeacherDialog);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, phoneEdit);

        label_8 = new QLabel(TeacherDialog);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, label_8);

        emailEdit = new QLineEdit(TeacherDialog);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, emailEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(TeacherDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TeacherDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TeacherDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TeacherDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherDialog)
    {
        TeacherDialog->setWindowTitle(QCoreApplication::translate("TeacherDialog", "\346\225\231\345\270\210\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("TeacherDialog", "\345\267\245\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("TeacherDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("TeacherDialog", "\347\224\267", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("TeacherDialog", "\345\245\263", nullptr));

        label_4->setText(QCoreApplication::translate("TeacherDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherDialog", "\351\231\242\347\263\273\357\274\232", nullptr));
        departmentComboBox->setItemText(0, QCoreApplication::translate("TeacherDialog", "\350\256\241\347\256\227\346\234\272\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(1, QCoreApplication::translate("TeacherDialog", "\346\225\260\345\255\246\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(2, QCoreApplication::translate("TeacherDialog", "\347\211\251\347\220\206\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(3, QCoreApplication::translate("TeacherDialog", "\345\244\226\345\233\275\350\257\255\345\255\246\351\231\242", nullptr));
        departmentComboBox->setItemText(4, QCoreApplication::translate("TeacherDialog", "\347\273\217\346\265\216\347\256\241\347\220\206\345\255\246\351\231\242", nullptr));

        label_6->setText(QCoreApplication::translate("TeacherDialog", "\350\201\214\347\247\260\357\274\232", nullptr));
        titleComboBox->setItemText(0, QCoreApplication::translate("TeacherDialog", "\346\225\231\346\216\210", nullptr));
        titleComboBox->setItemText(1, QCoreApplication::translate("TeacherDialog", "\345\211\257\346\225\231\346\216\210", nullptr));
        titleComboBox->setItemText(2, QCoreApplication::translate("TeacherDialog", "\350\256\262\345\270\210", nullptr));
        titleComboBox->setItemText(3, QCoreApplication::translate("TeacherDialog", "\345\212\251\346\225\231", nullptr));

        label_7->setText(QCoreApplication::translate("TeacherDialog", "\347\224\265\350\257\235\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("TeacherDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherDialog: public Ui_TeacherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERDIALOG_H
