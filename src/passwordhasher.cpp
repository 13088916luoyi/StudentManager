#include "passwordhasher.h"
#include <QCryptographicHash>
#include <QUuid>

QString PasswordHasher::hashPassword(const QString& password, const QString& salt)
{
    QByteArray data = (password + salt).toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

QString PasswordHasher::generateSalt()
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

bool PasswordHasher::verifyPassword(const QString& password, const QString& salt, const QString& hash)
{
    return hashPassword(password, salt) == hash;
}
