#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connect(const QString& dbPath)
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(dbPath);

    if (!m_database.open()) {
        qDebug() << "数据库连接失败:" << m_database.lastError().text();
        return false;
    }

    qDebug() << "数据库连接成功";
    return true;
}

void DatabaseManager::disconnect()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

QSqlDatabase& DatabaseManager::database()
{
    return m_database;
}

bool DatabaseManager::initializeTables()
{
    if (!createUsersTable()) return false;
    if (!createStudentsTable()) return false;
    if (!createTeachersTable()) return false;
    if (!createCoursesTable()) return false;
    if (!createGradesTable()) return false;
    if (!createCourseStudentsTable()) return false;
    if (!createIndexes()) return false;

    qDebug() << "所有数据表创建成功";
    return true;
}

bool DatabaseManager::createUsersTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username VARCHAR(50) UNIQUE NOT NULL,
            password VARCHAR(255) NOT NULL,
            salt VARCHAR(255) NOT NULL,
            role VARCHAR(20) NOT NULL CHECK(role IN ('admin', 'teacher', 'student')),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建users表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createStudentsTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER UNIQUE,
            student_no VARCHAR(20) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            gender VARCHAR(10) CHECK(gender IN ('男', '女')),
            age INTEGER,
            department VARCHAR(100),
            class_name VARCHAR(50),
            phone VARCHAR(20),
            email VARCHAR(100),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建students表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createTeachersTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS teachers (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER UNIQUE,
            teacher_no VARCHAR(20) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            gender VARCHAR(10) CHECK(gender IN ('男', '女')),
            age INTEGER,
            department VARCHAR(100),
            title VARCHAR(50),
            phone VARCHAR(20),
            email VARCHAR(100),
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users(id) ON DELETE CASCADE
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建teachers表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createCoursesTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            course_no VARCHAR(20) UNIQUE NOT NULL,
            course_name VARCHAR(100) NOT NULL,
            teacher_id INTEGER,
            credit REAL,
            hours INTEGER,
            description TEXT,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (teacher_id) REFERENCES teachers(id) ON DELETE SET NULL
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建courses表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createGradesTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS grades (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER NOT NULL,
            course_id INTEGER NOT NULL,
            grade REAL CHECK(grade >= 0 AND grade <= 100),
            semester VARCHAR(20),
            exam_type VARCHAR(50),
            remarks TEXT,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            updated_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE,
            FOREIGN KEY (course_id) REFERENCES courses(id) ON DELETE CASCADE,
            UNIQUE(student_id, course_id, semester)
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建grades表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createCourseStudentsTable()
{
    QSqlQuery query(m_database);
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS course_students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            course_id INTEGER NOT NULL,
            student_id INTEGER NOT NULL,
            enroll_date DATE,
            created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (course_id) REFERENCES courses(id) ON DELETE CASCADE,
            FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE,
            UNIQUE(course_id, student_id)
        )
    )";

    if (!query.exec(sql)) {
        qDebug() << "创建course_students表失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::createIndexes()
{
    QSqlQuery query(m_database);
    QStringList indexes = {
        "CREATE INDEX IF NOT EXISTS idx_students_student_no ON students(student_no)",
        "CREATE INDEX IF NOT EXISTS idx_grades_student_id ON grades(student_id)",
        "CREATE INDEX IF NOT EXISTS idx_grades_course_id ON grades(course_id)",
        "CREATE INDEX IF NOT EXISTS idx_courses_teacher_id ON courses(teacher_id)"
    };

    for (const QString& sql : indexes) {
        if (!query.exec(sql)) {
            qDebug() << "创建索引失败:" << query.lastError().text();
            return false;
        }
    }
    return true;
}
