#include "user.h"

User::User(int id, const QString& username, const QString& role)
    : m_id(id), m_username(username), m_role(role)
{
}
