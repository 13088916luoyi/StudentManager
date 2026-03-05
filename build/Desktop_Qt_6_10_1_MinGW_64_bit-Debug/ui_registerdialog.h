/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordEdit;
    QLabel *roleLabel;
    QComboBox *roleComboBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *registerButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(RegisterDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(RegisterDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        titleLabel->setFont(font);

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        usernameLabel = new QLabel(RegisterDialog);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, usernameLabel);

        usernameEdit = new QLineEdit(RegisterDialog);
        usernameEdit->setObjectName("usernameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameEdit);

        passwordLabel = new QLabel(RegisterDialog);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, passwordLabel);

        passwordEdit = new QLineEdit(RegisterDialog);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);

        confirmPasswordLabel = new QLabel(RegisterDialog);
        confirmPasswordLabel->setObjectName("confirmPasswordLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, confirmPasswordLabel);

        confirmPasswordEdit = new QLineEdit(RegisterDialog);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, confirmPasswordEdit);

        roleLabel = new QLabel(RegisterDialog);
        roleLabel->setObjectName("roleLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, roleLabel);

        roleComboBox = new QComboBox(RegisterDialog);
        roleComboBox->setObjectName("roleComboBox");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, roleComboBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        registerButton = new QPushButton(RegisterDialog);
        registerButton->setObjectName("registerButton");

        horizontalLayout->addWidget(registerButton);

        cancelButton = new QPushButton(RegisterDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        usernameLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201:", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        roleLabel->setText(QCoreApplication::translate("RegisterDialog", "\350\247\222\350\211\262:", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
