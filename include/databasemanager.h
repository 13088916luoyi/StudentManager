#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    bool connect(const QString& dbPath = "studentmanager.db");
    void disconnect();
    bool initializeTables();
    QSqlDatabase& database();

private:
    DatabaseManager() = default;
    ~DatabaseManager() = default;
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase m_database;
    bool createUsersTable();
    bool createStudentsTable();
    bool createTeachersTable();
    bool createCoursesTable();
    bool createGradesTable();
    bool createCourseStudentsTable();
    bool createIndexes();
};

#endif // DATABASEMANAGER_H
