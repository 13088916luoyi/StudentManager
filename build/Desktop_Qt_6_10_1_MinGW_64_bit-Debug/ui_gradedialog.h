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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GradeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *studentComboBox;
    QLabel *label_2;
    QComboBox *courseComboBox;
    QLabel *label_3;
    QDoubleSpinBox *gradeSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GradeDialog)
    {
        if (GradeDialog->objectName().isEmpty())
            GradeDialog->setObjectName("GradeDialog");
        GradeDialog->resize(450, 280);
        GradeDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QLabel {\n"
"    font-size: 13px;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"QComboBox, QDoubleSpinBox {\n"
"    padding: 8px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 13px;\n"
"    min-height: 35px;\n"
"}\n"
"QComboBox:focus, QDoubleSpinBox:focus {\n"
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
"    color: #"
                        "333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]:hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}"));
        verticalLayout = new QVBoxLayout(GradeDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(GradeDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(GradeDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        studentComboBox = new QComboBox(GradeDialog);
        studentComboBox->setObjectName("studentComboBox");
        studentComboBox->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentComboBox);

        label_2 = new QLabel(GradeDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        courseComboBox = new QComboBox(GradeDialog);
        courseComboBox->setObjectName("courseComboBox");
        courseComboBox->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, courseComboBox);

        label_3 = new QLabel(GradeDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        gradeSpinBox = new QDoubleSpinBox(GradeDialog);
        gradeSpinBox->setObjectName("gradeSpinBox");
        gradeSpinBox->setMinimumSize(QSize(250, 35));
        gradeSpinBox->setMinimum(0.000000000000000);
        gradeSpinBox->setMaximum(100.000000000000000);
        gradeSpinBox->setValue(60.000000000000000);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, gradeSpinBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(GradeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GradeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, GradeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GradeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(GradeDialog);
    } // setupUi

    void retranslateUi(QDialog *GradeDialog)
    {
        GradeDialog->setWindowTitle(QCoreApplication::translate("GradeDialog", "\346\210\220\347\273\251\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("GradeDialog", "\346\210\220\347\273\251\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("GradeDialog", "\345\255\246\347\224\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("GradeDialog", "\350\257\276\347\250\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("GradeDialog", "\346\210\220\347\273\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GradeDialog: public Ui_GradeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEDIALOG_H
