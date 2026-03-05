#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "user.h"

namespace Ui {
class AccountDialog;
}

class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDialog(QWidget *parent = nullptr);
    ~AccountDialog();

    void setUser(const User& user);
    User getUser() const;
    QString getPassword() const;
    QString getConfirmPassword() const;
    void setEditMode(bool edit);

private:
    void togglePasswordVisibility(QLineEdit* passwordEdit, QPushButton* button);
    
    Ui::AccountDialog *ui;
    bool m_editMode = false;
    int m_userId = 0;
};

#endif // ACCOUNTDIALOG_H
