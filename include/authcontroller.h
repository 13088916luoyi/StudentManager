#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include "user.h"
#include "userdao.h"
#include <QObject>

class AuthController : public QObject
{
    Q_OBJECT

public:
    static AuthController& instance();

    bool login(const QString& username, const QString& password);
    bool registerUser(const QString& username, const QString& password, const QString& role);
    void logout();
    User getCurrentUser() const;
    bool isAuthenticated() const;

signals:
    void loginSuccess(const User& user);
    void loginFailed(const QString& message);
    void logoutSuccess();

private:
    AuthController(QObject* parent = nullptr);
    User m_currentUser;
    bool m_authenticated = false;
    UserDAO m_userDAO;
};

#endif // AUTHCONTROLLER_H
