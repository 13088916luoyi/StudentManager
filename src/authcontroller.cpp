#include "authcontroller.h"
#include "passwordhasher.h"
#include <QDebug>

AuthController& AuthController::instance()
{
    static AuthController instance;
    return instance;
}

AuthController::AuthController(QObject* parent)
    : QObject(parent)
{
}

bool AuthController::login(const QString& username, const QString& password)
{
    qDebug() << "AuthController::login - 用户名:" << username;
    
    auto userOpt = m_userDAO.findByUsername(username);
    if (!userOpt.has_value()) {
        qDebug() << "用户不存在";
        emit loginFailed("用户名不存在");
        return false;
    }

    User user = userOpt.value();
    qDebug() << "开始验证密码";
    qDebug() << "输入密码:" << password;
    qDebug() << "存储的盐值:" << user.salt();
    qDebug() << "存储的哈希:" << user.password();
    
    QString calculatedHash = PasswordHasher::hashPassword(password, user.salt());
    qDebug() << "计算的哈希:" << calculatedHash;
    qDebug() << "哈希匹配:" << (calculatedHash == user.password());
    
    if (!PasswordHasher::verifyPassword(password, user.salt(), user.password())) {
        qDebug() << "密码验证失败";
        emit loginFailed("密码错误");
        return false;
    }

    qDebug() << "登录成功";
    m_currentUser = user;
    m_authenticated = true;
    emit loginSuccess(user);
    return true;
}

bool AuthController::registerUser(const QString& username, const QString& password, const QString& role)
{
    // 检查用户名是否已存在
    auto existingUser = m_userDAO.findByUsername(username);
    if (existingUser.has_value()) {
        return false;
    }

    // 创建新用户
    User user;
    user.setUsername(username);
    QString salt = PasswordHasher::generateSalt();
    user.setSalt(salt);
    user.setPassword(PasswordHasher::hashPassword(password, salt));
    user.setRole(role);

    return m_userDAO.insert(user);
}

void AuthController::logout()
{
    m_currentUser = User();
    m_authenticated = false;
    emit logoutSuccess();
}

User AuthController::getCurrentUser() const
{
    return m_currentUser;
}

bool AuthController::isAuthenticated() const
{
    return m_authenticated;
}
