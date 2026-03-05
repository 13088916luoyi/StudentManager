/********************************************************************************
** Form generated from reading UI file 'gradeeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEEDITDIALOG_H
#define UI_GRADEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GradeEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_studentNo;
    QLabel *studentNoLabel;
    QLabel *label_name;
    QLabel *studentNameLabel;
    QLabel *label_grade;
    QSpinBox *gradeSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GradeEditDialog)
    {
        if (GradeEditDialog->objectName().isEmpty())
            GradeEditDialog->setObjectName("GradeEditDialog");
        GradeEditDialog->resize(350, 200);
        verticalLayout = new QVBoxLayout(GradeEditDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        label_studentNo = new QLabel(GradeEditDialog);
        label_studentNo->setObjectName("label_studentNo");
        QFont font;
        font.setPointSize(11);
        label_studentNo->setFont(font);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_studentNo);

        studentNoLabel = new QLabel(GradeEditDialog);
        studentNoLabel->setObjectName("studentNoLabel");
        studentNoLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentNoLabel);

        label_name = new QLabel(GradeEditDialog);
        label_name->setObjectName("label_name");
        label_name->setFont(font);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_name);

        studentNameLabel = new QLabel(GradeEditDialog);
        studentNameLabel->setObjectName("studentNameLabel");
        studentNameLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, studentNameLabel);

        label_grade = new QLabel(GradeEditDialog);
        label_grade->setObjectName("label_grade");
        label_grade->setFont(font);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_grade);

        gradeSpinBox = new QSpinBox(GradeEditDialog);
        gradeSpinBox->setObjectName("gradeSpinBox");
        gradeSpinBox->setFont(font);
        gradeSpinBox->setMinimum(0);
        gradeSpinBox->setMaximum(100);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, gradeSpinBox);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(GradeEditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GradeEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, GradeEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GradeEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(GradeEditDialog);
    } // setupUi

    void retranslateUi(QDialog *GradeEditDialog)
    {
        GradeEditDialog->setWindowTitle(QCoreApplication::translate("GradeEditDialog", "\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        label_studentNo->setText(QCoreApplication::translate("GradeEditDialog", "\345\255\246\345\217\267\357\274\232", nullptr));
        studentNoLabel->setText(QCoreApplication::translate("GradeEditDialog", "-", nullptr));
        label_name->setText(QCoreApplication::translate("GradeEditDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        studentNameLabel->setText(QCoreApplication::translate("GradeEditDialog", "-", nullptr));
        label_grade->setText(QCoreApplication::translate("GradeEditDialog", "\346\210\220\347\273\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GradeEditDialog: public Ui_GradeEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEEDITDIALOG_H
