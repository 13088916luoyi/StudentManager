#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    User getLoggedInUser() const { return m_loggedInUser; }

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    Ui::LoginDialog *ui;
    User m_loggedInUser;
};

#endif // LOGINDIALOG_H
