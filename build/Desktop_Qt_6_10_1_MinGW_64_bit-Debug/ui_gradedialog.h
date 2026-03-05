/********************************************************************************
** Form generated from reading UI file 'gradedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEDIALOG_H
#define UI_GRADEDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GradeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *studentComboBox;
    QLabel *label_2;
    QComboBox *courseComboBox;
    QLabel *label_3;
    QDoubleSpinBox *gradeSpinBox;
    QLabel *label_4;
    QComboBox *semesterComboBox;
    QLabel *label_5;
    QComboBox *examTypeComboBox;
    QLabel *label_6;
    QLineEdit *remarksEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GradeDialog)
    {
        if (GradeDialog->objectName().isEmpty())
            GradeDialog->setObjectName("GradeDialog");
        GradeDialog->resize(400, 320);
        verticalLayout = new QVBoxLayout(GradeDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(GradeDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        studentComboBox = new QComboBox(GradeDialog);
        studentComboBox->setObjectName("studentComboBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentComboBox);

        label_2 = new QLabel(GradeDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        courseComboBox = new QComboBox(GradeDialog);
        courseComboBox->setObjectName("courseComboBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, courseComboBox);

        label_3 = new QLabel(GradeDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        gradeSpinBox = new QDoubleSpinBox(GradeDialog);
        gradeSpinBox->setObjectName("gradeSpinBox");
        gradeSpinBox->setMinimum(0.000000000000000);
        gradeSpinBox->setMaximum(100.000000000000000);
        gradeSpinBox->setValue(60.000000000000000);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, gradeSpinBox);

        label_4 = new QLabel(GradeDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        semesterComboBox = new QComboBox(GradeDialog);
        semesterComboBox->addItem(QString());
        semesterComboBox->addItem(QString());
        semesterComboBox->addItem(QString());
        semesterComboBox->setObjectName("semesterComboBox");
        semesterComboBox->setEditable(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, semesterComboBox);

        label_5 = new QLabel(GradeDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        examTypeComboBox = new QComboBox(GradeDialog);
        examTypeComboBox->addItem(QString());
        examTypeComboBox->addItem(QString());
        examTypeComboBox->addItem(QString());
        examTypeComboBox->setObjectName("examTypeComboBox");
        examTypeComboBox->setEditable(true);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, examTypeComboBox);

        label_6 = new QLabel(GradeDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        remarksEdit = new QLineEdit(GradeDialog);
        remarksEdit->setObjectName("remarksEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, remarksEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(GradeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GradeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, GradeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GradeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(GradeDialog);
    } // setupUi

    void retranslateUi(QDialog *GradeDialog)
    {
        GradeDialog->setWindowTitle(QCoreApplication::translate("GradeDialog", "\346\210\220\347\273\251\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("GradeDialog", "\345\255\246\347\224\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("GradeDialog", "\350\257\276\347\250\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("GradeDialog", "\346\210\220\347\273\251\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("GradeDialog", "\345\255\246\346\234\237\357\274\232", nullptr));
        semesterComboBox->setItemText(0, QCoreApplication::translate("GradeDialog", "2024-2025-1", nullptr));
        semesterComboBox->setItemText(1, QCoreApplication::translate("GradeDialog", "2024-2025-2", nullptr));
        semesterComboBox->setItemText(2, QCoreApplication::translate("GradeDialog", "2025-2026-1", nullptr));

        label_5->setText(QCoreApplication::translate("GradeDialog", "\350\200\203\350\257\225\347\261\273\345\236\213\357\274\232", nullptr));
        examTypeComboBox->setItemText(0, QCoreApplication::translate("GradeDialog", "\346\234\237\346\234\253\350\200\203\350\257\225", nullptr));
        examTypeComboBox->setItemText(1, QCoreApplication::translate("GradeDialog", "\346\234\237\344\270\255\350\200\203\350\257\225", nullptr));
        examTypeComboBox->setItemText(2, QCoreApplication::translate("GradeDialog", "\345\271\263\346\227\266\346\210\220\347\273\251", nullptr));

        label_6->setText(QCoreApplication::translate("GradeDialog", "\345\244\207\346\263\250\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GradeDialog: public Ui_GradeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEDIALOG_H
