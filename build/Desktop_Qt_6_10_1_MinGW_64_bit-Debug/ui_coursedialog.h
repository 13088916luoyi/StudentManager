/********************************************************************************
** Form generated from reading UI file 'coursedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEDIALOG_H
#define UI_COURSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *courseNoEdit;
    QLabel *label_2;
    QLineEdit *courseNameEdit;
    QLabel *label_3;
    QComboBox *teacherComboBox;
    QLabel *label_4;
    QDoubleSpinBox *creditSpinBox;
    QLabel *label_5;
    QSpinBox *hoursSpinBox;
    QLabel *label_6;
    QTextEdit *descriptionEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CourseDialog)
    {
        if (CourseDialog->objectName().isEmpty())
            CourseDialog->setObjectName("CourseDialog");
        CourseDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(CourseDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(CourseDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        courseNoEdit = new QLineEdit(CourseDialog);
        courseNoEdit->setObjectName("courseNoEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, courseNoEdit);

        label_2 = new QLabel(CourseDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        courseNameEdit = new QLineEdit(CourseDialog);
        courseNameEdit->setObjectName("courseNameEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, courseNameEdit);

        label_3 = new QLabel(CourseDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        teacherComboBox = new QComboBox(CourseDialog);
        teacherComboBox->setObjectName("teacherComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, teacherComboBox);

        label_4 = new QLabel(CourseDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        creditSpinBox = new QDoubleSpinBox(CourseDialog);
        creditSpinBox->setObjectName("creditSpinBox");
        creditSpinBox->setMinimum(0.500000000000000);
        creditSpinBox->setMaximum(10.000000000000000);
        creditSpinBox->setSingleStep(0.500000000000000);
        creditSpinBox->setValue(3.000000000000000);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, creditSpinBox);

        label_5 = new QLabel(CourseDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        hoursSpinBox = new QSpinBox(CourseDialog);
        hoursSpinBox->setObjectName("hoursSpinBox");
        hoursSpinBox->setMinimum(8);
        hoursSpinBox->setMaximum(200);
        hoursSpinBox->setSingleStep(8);
        hoursSpinBox->setValue(48);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, hoursSpinBox);

        label_6 = new QLabel(CourseDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        descriptionEdit = new QTextEdit(CourseDialog);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMaximumSize(QSize(16777215, 80));

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, descriptionEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(CourseDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CourseDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CourseDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CourseDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CourseDialog);
    } // setupUi

    void retranslateUi(QDialog *CourseDialog)
    {
        CourseDialog->setWindowTitle(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CourseDialog", "\346\216\210\350\257\276\346\225\231\345\270\210\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("CourseDialog", "\345\255\246\345\210\206\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CourseDialog", "\345\255\246\346\227\266\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("CourseDialog", "\346\217\217\350\277\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseDialog: public Ui_CourseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEDIALOG_H
