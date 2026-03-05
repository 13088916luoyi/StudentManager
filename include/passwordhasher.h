#ifndef PASSWORDHASHER_H
#define PASSWORDHASHER_H

#include <QString>

class PasswordHasher
{
public:
    static QString hashPassword(const QString& password, const QString& salt);
    static QString generateSalt();
    static bool verifyPassword(const QString& password, const QString& salt, const QString& hash);
};

#endif // PASSWORDHASHER_H
