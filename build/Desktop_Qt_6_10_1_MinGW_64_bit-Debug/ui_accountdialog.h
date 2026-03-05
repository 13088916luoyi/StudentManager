/********************************************************************************
** Form generated from reading UI file 'accountdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTDIALOG_H
#define UI_ACCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AccountDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLabel *label_2;
    QHBoxLayout *passwordLayout;
    QLineEdit *passwordEdit;
    QPushButton *showPasswordBtn;
    QLabel *label_3;
    QHBoxLayout *confirmPasswordLayout;
    QLineEdit *confirmPasswordEdit;
    QPushButton *showConfirmPasswordBtn;
    QLabel *label_4;
    QComboBox *roleComboBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AccountDialog)
    {
        if (AccountDialog->objectName().isEmpty())
            AccountDialog->setObjectName("AccountDialog");
        AccountDialog->resize(480, 320);
        AccountDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QLabel {\n"
"    font-size: 13px;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"QLineEdit, QComboBox {\n"
"    padding: 8px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 13px;\n"
"    min-height: 35px;\n"
"}\n"
"QLineEdit:focus, QComboBox:focus {\n"
"    border: 2px solid #4a90d9;\n"
"}\n"
"QPushButton {\n"
"    padding: 8px 12px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    min-width: 60px;\n"
"}\n"
"QPushButton#showPasswordBtn, QPushButton#showConfirmPasswordBtn {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton#showPasswordBtn:hover, QPushButton#showConfirmPasswordBtn:hover {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"QPushButton[text=\"\347\241\256\345\256\232\"], QPushButton[text=\"OK\"] {\n"
"    background-color: #4a90d9;\n"
"    color: white;\n"
"}\n"
"QPushButton[tex"
                        "t=\"\347\241\256\345\256\232\"]:hover, QPushButton[text=\"OK\"]:hover {\n"
"    background-color: #3a7bc8;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"], QPushButton[text=\"Cancel\"] {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]:hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}"));
        verticalLayout = new QVBoxLayout(AccountDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        titleLabel = new QLabel(AccountDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4a90d9; margin-bottom: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        label = new QLabel(AccountDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        usernameEdit = new QLineEdit(AccountDialog);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setMinimumSize(QSize(280, 35));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameEdit);

        label_2 = new QLabel(AccountDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        passwordLayout = new QHBoxLayout();
        passwordLayout->setObjectName("passwordLayout");
        passwordEdit = new QLineEdit(AccountDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setMinimumSize(QSize(200, 35));
        passwordEdit->setEchoMode(QLineEdit::Password);

        passwordLayout->addWidget(passwordEdit);

        showPasswordBtn = new QPushButton(AccountDialog);
        showPasswordBtn->setObjectName("showPasswordBtn");
        showPasswordBtn->setMinimumSize(QSize(60, 35));
        showPasswordBtn->setMaximumSize(QSize(60, 35));

        passwordLayout->addWidget(showPasswordBtn);


        formLayout->setLayout(1, QFormLayout::ItemRole::FieldRole, passwordLayout);

        label_3 = new QLabel(AccountDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        confirmPasswordLayout = new QHBoxLayout();
        confirmPasswordLayout->setObjectName("confirmPasswordLayout");
        confirmPasswordEdit = new QLineEdit(AccountDialog);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        confirmPasswordEdit->setMinimumSize(QSize(200, 35));
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        confirmPasswordLayout->addWidget(confirmPasswordEdit);

        showConfirmPasswordBtn = new QPushButton(AccountDialog);
        showConfirmPasswordBtn->setObjectName("showConfirmPasswordBtn");
        showConfirmPasswordBtn->setMinimumSize(QSize(60, 35));
        showConfirmPasswordBtn->setMaximumSize(QSize(60, 35));

        confirmPasswordLayout->addWidget(showConfirmPasswordBtn);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, confirmPasswordLayout);

        label_4 = new QLabel(AccountDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        roleComboBox = new QComboBox(AccountDialog);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");
        roleComboBox->setMinimumSize(QSize(280, 35));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, roleComboBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AccountDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AccountDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AccountDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AccountDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AccountDialog);
    } // setupUi

    void retranslateUi(QDialog *AccountDialog)
    {
        AccountDialog->setWindowTitle(QCoreApplication::translate("AccountDialog", "\350\264\246\345\217\267\344\277\241\346\201\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("AccountDialog", "\350\264\246\345\217\267\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("AccountDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("AccountDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("AccountDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("AccountDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        showPasswordBtn->setText(QCoreApplication::translate("AccountDialog", "\346\230\276\347\244\272", nullptr));
        label_3->setText(QCoreApplication::translate("AccountDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        confirmPasswordEdit->setPlaceholderText(QCoreApplication::translate("AccountDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        showConfirmPasswordBtn->setText(QCoreApplication::translate("AccountDialog", "\346\230\276\347\244\272", nullptr));
        label_4->setText(QCoreApplication::translate("AccountDialog", "\350\247\222\350\211\262\357\274\232", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("AccountDialog", "admin", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("AccountDialog", "teacher", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("AccountDialog", "student", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AccountDialog: public Ui_AccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTDIALOG_H
