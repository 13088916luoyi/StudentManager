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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *courseNoEdit;
    QLabel *label_2;
    QLineEdit *courseNameEdit;
    QLabel *label_4;
    QDoubleSpinBox *creditSpinBox;
    QLabel *label_5;
    QSpinBox *hoursSpinBox;
    QLabel *label_6;
    QComboBox *courseTypeComboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CourseDialog)
    {
        if (CourseDialog->objectName().isEmpty())
            CourseDialog->setObjectName("CourseDialog");
        CourseDialog->resize(450, 280);
        CourseDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QLabel {\n"
"    font-size: 13px;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit, QComboBox, QDoubleSpinBox, QSpinBox {\n"
"    padding: 8px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 13px;\n"
"    min-height: 35px;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus, QDoubleSpinBox:focus, QSpinBox:focus {\n"
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
"QPushButton[text=\"\345\217\226\346\266\210\"], QPushButton[text=\"Cancel\"]"
                        " {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]:hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}"));
        verticalLayout = new QVBoxLayout(CourseDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(CourseDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(CourseDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        courseNoEdit = new QLineEdit(CourseDialog);
        courseNoEdit->setObjectName("courseNoEdit");
        courseNoEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, courseNoEdit);

        label_2 = new QLabel(CourseDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        courseNameEdit = new QLineEdit(CourseDialog);
        courseNameEdit->setObjectName("courseNameEdit");
        courseNameEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, courseNameEdit);

        label_4 = new QLabel(CourseDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_4);

        creditSpinBox = new QDoubleSpinBox(CourseDialog);
        creditSpinBox->setObjectName("creditSpinBox");
        creditSpinBox->setMinimumSize(QSize(250, 35));
        creditSpinBox->setMinimum(0.500000000000000);
        creditSpinBox->setMaximum(10.000000000000000);
        creditSpinBox->setSingleStep(0.500000000000000);
        creditSpinBox->setValue(3.000000000000000);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, creditSpinBox);

        label_5 = new QLabel(CourseDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_5);

        hoursSpinBox = new QSpinBox(CourseDialog);
        hoursSpinBox->setObjectName("hoursSpinBox");
        hoursSpinBox->setMinimumSize(QSize(250, 35));
        hoursSpinBox->setMinimum(8);
        hoursSpinBox->setMaximum(200);
        hoursSpinBox->setSingleStep(8);
        hoursSpinBox->setValue(48);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, hoursSpinBox);

        label_6 = new QLabel(CourseDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_6);

        courseTypeComboBox = new QComboBox(CourseDialog);
        courseTypeComboBox->addItem(QString());
        courseTypeComboBox->addItem(QString());
        courseTypeComboBox->setObjectName("courseTypeComboBox");
        courseTypeComboBox->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, courseTypeComboBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(CourseDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CourseDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CourseDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CourseDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CourseDialog);
    } // setupUi

    void retranslateUi(QDialog *CourseDialog)
    {
        CourseDialog->setWindowTitle(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\345\217\267\357\274\232", nullptr));
        courseNoEdit->setPlaceholderText(QCoreApplication::translate("CourseDialog", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\345\220\215\357\274\232", nullptr));
        courseNameEdit->setPlaceholderText(QCoreApplication::translate("CourseDialog", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("CourseDialog", "\345\255\246\345\210\206\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CourseDialog", "\345\255\246\346\227\266\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("CourseDialog", "\350\257\276\347\250\213\347\261\273\345\210\253\357\274\232", nullptr));
        courseTypeComboBox->setItemText(0, QCoreApplication::translate("CourseDialog", "\345\277\205\344\277\256", nullptr));
        courseTypeComboBox->setItemText(1, QCoreApplication::translate("CourseDialog", "\351\200\211\344\277\256", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CourseDialog: public Ui_CourseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEDIALOG_H
