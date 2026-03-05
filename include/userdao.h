#ifndef USERDAO_H
#define USERDAO_H

#include "user.h"
#include <QVector>
#include <optional>

class UserDAO
{
public:
    UserDAO() = default;

    bool insert(const User& user);
    bool update(const User& user);
    bool updateWithPassword(const User& user);
    bool updateRole(const User& user);
    bool remove(int id);
    std::optional<User> findById(int id);
    QVector<User> findAll();
    std::optional<User> findByUsername(const QString& username);
    QVector<User> findByRole(const QString& role);

private:
    User createUserFromQuery(class QSqlQuery& query);
};

#endif // USERDAO_H
