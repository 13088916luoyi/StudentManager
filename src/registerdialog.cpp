#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "authcontroller.h"
#include <QMessageBox>

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setWindowTitle("用户注册");

    ui->roleComboBox->addItem("学生", "student");
    ui->roleComboBox->addItem("教师", "teacher");
    ui->roleComboBox->addItem("管理员", "admin");

    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &RegisterDialog::onCancelClicked);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::onRegisterClicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirmPassword = ui->confirmPasswordEdit->text();
    QString role = ui->roleComboBox->currentData().toString();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "提示", "用户名和密码不能为空");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "提示", "两次输入的密码不一致");
        return;
    }

    if (password.length() < 6) {
        QMessageBox::warning(this, "提示", "密码长度不能少于6位");
        return;
    }

    if (AuthController::instance().registerUser(username, password, role)) {
        QMessageBox::information(this, "成功", "注册成功");
        accept();
    } else {
        QMessageBox::warning(this, "失败", "注册失败，用户名可能已存在");
    }
}

void RegisterDialog::onCancelClicked()
{
    reject();
}
