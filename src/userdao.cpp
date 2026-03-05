#include "userdao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool UserDAO::insert(const User& user)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO users (username, password, salt, role) VALUES (:username, :password, :salt, :role)");
    query.bindValue(":username", user.username());
    query.bindValue(":password", user.password());
    query.bindValue(":salt", user.salt());
    query.bindValue(":role", user.role());

    if (!query.exec()) {
        qDebug() << "插入用户失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool UserDAO::update(const User& user)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE users SET username=:username, password=:password, salt=:salt, role=:role WHERE id=:id");
    query.bindValue(":username", user.username());
    query.bindValue(":password", user.password());
    query.bindValue(":salt", user.salt());
    query.bindValue(":role", user.role());
    query.bindValue(":id", user.id());

    if (!query.exec()) {
        qDebug() << "更新用户失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool UserDAO::updateWithPassword(const User& user)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE users SET password=:password, salt=:salt, role=:role WHERE id=:id");
    query.bindValue(":password", user.password());
    query.bindValue(":salt", user.salt());
    query.bindValue(":role", user.role());
    query.bindValue(":id", user.id());

    if (!query.exec()) {
        qDebug() << "更新用户密码失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool UserDAO::updateRole(const User& user)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE users SET role=:role WHERE id=:id");
    query.bindValue(":role", user.role());
    query.bindValue(":id", user.id());

    if (!query.exec()) {
        qDebug() << "更新用户角色失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool UserDAO::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM users WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "删除用户失败:" << query.lastError().text();
        return false;
    }
    return true;
}

std::optional<User> UserDAO::findById(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM users WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return createUserFromQuery(query);
    }
    return std::nullopt;
}

QVector<User> UserDAO::findAll()
{
    QVector<User> users;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM users")) {
        while (query.next()) {
            users.append(createUserFromQuery(query));
        }
    }
    return users;
}

std::optional<User> UserDAO::findByUsername(const QString& username)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM users WHERE username=:username");
    query.bindValue(":username", username);

    qDebug() << "查询用户:" << username;
    
    if (query.exec() && query.next()) {
        User user = createUserFromQuery(query);
        qDebug() << "找到用户 - ID:" << user.id() << "角色:" << user.role();
        qDebug() << "密码哈希长度:" << user.password().length();
        qDebug() << "盐值长度:" << user.salt().length();
        return user;
    }
    
    qDebug() << "未找到用户:" << username;
    if (!query.exec()) {
        qDebug() << "SQL错误:" << query.lastError().text();
    }
    
    return std::nullopt;
}

QVector<User> UserDAO::findByRole(const QString& role)
{
    QVector<User> users;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM users WHERE role=:role");
    query.bindValue(":role", role);

    if (query.exec()) {
        while (query.next()) {
            users.append(createUserFromQuery(query));
        }
    }
    return users;
}

User UserDAO::createUserFromQuery(QSqlQuery& query)
{
    User user;
    user.setId(query.value("id").toInt());
    user.setUsername(query.value("username").toString());
    user.setPassword(query.value("password").toString());
    user.setSalt(query.value("salt").toString());
    user.setRole(query.value("role").toString());
    return user;
}
