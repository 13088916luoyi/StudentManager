#include "permissionmanager.h"

PermissionManager& PermissionManager::instance()
{
    static PermissionManager instance;
    return instance;
}

PermissionManager::PermissionManager()
{
    m_rolePermissions["admin"] = {
        "user:read", "user:write",
        "student:read", "student:write",
        "teacher:read", "teacher:write",
        "course:read", "course:write",
        "grade:read", "grade:write"
    };

    m_rolePermissions["teacher"] = {
        "student:read",
        "course:read", "course:write",
        "grade:read", "grade:write"
    };

    m_rolePermissions["student"] = {
        "profile:read", "profile:write",
        "grade:read"
    };
}

bool PermissionManager::hasPermission(const QString& role, const QString& permission)
{
    return m_rolePermissions[role].contains(permission);
}

QStringList PermissionManager::getRolePermissions(const QString& role)
{
    return m_rolePermissions[role];
}
