#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User() = default;
    User(int id, const QString& username, const QString& role);

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    QString username() const { return m_username; }
    void setUsername(const QString& username) { m_username = username; }

    QString password() const { return m_password; }
    void setPassword(const QString& password) { m_password = password; }

    QString salt() const { return m_salt; }
    void setSalt(const QString& salt) { m_salt = salt; }

    QString role() const { return m_role; }
    void setRole(const QString& role) { m_role = role; }

private:
    int m_id = 0;
    QString m_username;
    QString m_password;
    QString m_salt;
    QString m_role;
};

#endif // USER_H
