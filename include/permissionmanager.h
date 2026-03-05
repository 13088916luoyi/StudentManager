#ifndef PERMISSIONMANAGER_H
#define PERMISSIONMANAGER_H

#include <QString>
#include <QStringList>
#include <QMap>

class PermissionManager
{
public:
    static PermissionManager& instance();
    bool hasPermission(const QString& role, const QString& permission);
    QStringList getRolePermissions(const QString& role);

private:
    PermissionManager();
    QMap<QString, QStringList> m_rolePermissions;
};

#endif // PERMISSIONMANAGER_H
