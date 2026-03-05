#include "logindialog.h"
#include "ui_logindialog.h"
#include "authcontroller.h"
#include "registerdialog.h"
#include <QMessageBox>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 - 登录");

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLoginClicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "提示", "用户名和密码不能为空");
        return;
    }

    qDebug() << "尝试登录 - 用户名:" << username;
    
    if (AuthController::instance().login(username, password)) {
        m_loggedInUser = AuthController::instance().getCurrentUser();
        qDebug() << "登录成功 - 角色:" << m_loggedInUser.role();
        accept();
    } else {
        qDebug() << "登录失败";
        QMessageBox::warning(this, "登录失败", "用户名或密码错误");
    }
}

void LoginDialog::onRegisterClicked()
{
    RegisterDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "成功", "注册成功，请登录");
    }
}
