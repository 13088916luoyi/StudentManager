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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherProfileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_teacherNo;
    QLabel *teacherNoLabel;
    QLabel *label_name;
    QLineEdit *nameEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeacherProfileDialog)
    {
        if (TeacherProfileDialog->objectName().isEmpty())
            TeacherProfileDialog->setObjectName("TeacherProfileDialog");
        TeacherProfileDialog->resize(450, 250);
        TeacherProfileDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"QGroupBox {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 6px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px;\n"
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
"QPushButton[text=\"\347\241\256"
                        "\345\256\232\"]:hover, QPushButton[text=\"OK\"]:hover {\n"
"    background-color: #3a7bc8;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"], QPushButton[text=\"Cancel\"] {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]:hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}"));
        verticalLayout = new QVBoxLayout(TeacherProfileDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(TeacherProfileDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        groupBox = new QGroupBox(TeacherProfileDialog);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
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
        nameEdit->setMinimumSize(QSize(250, 35));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, nameEdit);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(TeacherProfileDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeacherProfileDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TeacherProfileDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TeacherProfileDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TeacherProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherProfileDialog)
    {
        TeacherProfileDialog->setWindowTitle(QCoreApplication::translate("TeacherProfileDialog", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("TeacherProfileDialog", "\347\274\226\350\276\221\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TeacherProfileDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_teacherNo->setText(QCoreApplication::translate("TeacherProfileDialog", "\345\267\245\345\217\267\357\274\232", nullptr));
        teacherNoLabel->setText(QCoreApplication::translate("TeacherProfileDialog", "-", nullptr));
        label_name->setText(QCoreApplication::translate("TeacherProfileDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("TeacherProfileDialog", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherProfileDialog: public Ui_TeacherProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERPROFILEDIALOG_H
