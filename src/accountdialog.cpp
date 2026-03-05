#include "accountdialog.h"
#include "ui_accountdialog.h"
#include <QMessageBox>

AccountDialog::AccountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);
    setWindowTitle("账号信息");
    
    // 连接密码显示/隐藏按钮
    connect(ui->showPasswordBtn, &QPushButton::clicked, this, [this]() {
        togglePasswordVisibility(ui->passwordEdit, ui->showPasswordBtn);
    });
    connect(ui->showConfirmPasswordBtn, &QPushButton::clicked, this, [this]() {
        togglePasswordVisibility(ui->confirmPasswordEdit, ui->showConfirmPasswordBtn);
    });
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

void AccountDialog::togglePasswordVisibility(QLineEdit* passwordEdit, QPushButton* button)
{
    if (passwordEdit->echoMode() == QLineEdit::Password) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        button->setText("隐藏");
    } else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        button->setText("显示");
    }
}

void AccountDialog::setUser(const User& user)
{
    m_userId = user.id();
    ui->usernameEdit->setText(user.username());
    
    int roleIndex = ui->roleComboBox->findText(user.role());
    if (roleIndex >= 0) {
        ui->roleComboBox->setCurrentIndex(roleIndex);
    }
    
    // 编辑模式下，密码字段可选填（不填表示不修改密码）
    if (m_editMode) {
        ui->passwordEdit->setPlaceholderText("不填表示不修改密码");
        ui->confirmPasswordEdit->setPlaceholderText("不填表示不修改密码");
    }
}

User AccountDialog::getUser() const
{
    User user;
    user.setId(m_userId);
    user.setUsername(ui->usernameEdit->text().trimmed());
    user.setRole(ui->roleComboBox->currentText());
    return user;
}

QString AccountDialog::getPassword() const
{
    return ui->passwordEdit->text();
}

QString AccountDialog::getConfirmPassword() const
{
    return ui->confirmPasswordEdit->text();
}

void AccountDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑账号" : "添加账号");
    
    // 编辑模式下禁用用户名编辑
    ui->usernameEdit->setEnabled(!edit);
    
    if (edit) {
        ui->passwordEdit->setPlaceholderText("不填表示不修改密码");
        ui->confirmPasswordEdit->setPlaceholderText("不填表示不修改密码");
    }
}
