#include "studentdao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool StudentDAO::insert(const Student& student)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO students (user_id, student_no, name, class_name, major) "
                  "VALUES (:user_id, :student_no, :name, :class_name, :major)");
    query.bindValue(":user_id", student.userId() == 0 ? QVariant() : student.userId());
    query.bindValue(":student_no", student.studentNo());
    query.bindValue(":name", student.name());
    query.bindValue(":class_name", student.className());
    query.bindValue(":major", student.major());

    if (!query.exec()) {
        qDebug() << "插入学生失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool StudentDAO::update(const Student& student)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE students SET user_id=:user_id, student_no=:student_no, name=:name, "
                  "class_name=:class_name, major=:major WHERE id=:id");
    query.bindValue(":user_id", student.userId() == 0 ? QVariant() : student.userId());
    query.bindValue(":student_no", student.studentNo());
    query.bindValue(":name", student.name());
    query.bindValue(":class_name", student.className());
    query.bindValue(":major", student.major());
    query.bindValue(":id", student.id());

    if (!query.exec()) {
        qDebug() << "更新学生失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool StudentDAO::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM students WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "删除学生失败:" << query.lastError().text();
        return false;
    }
    return true;
}

std::optional<Student> StudentDAO::findById(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM students WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return createStudentFromQuery(query);
    }
    return std::nullopt;
}

QVector<Student> StudentDAO::findAll()
{
    QVector<Student> students;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM students")) {
        while (query.next()) {
            students.append(createStudentFromQuery(query));
        }
    }
    return students;
}

std::optional<Student> StudentDAO::findByStudentNo(const QString& studentNo)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM students WHERE student_no=:student_no");
    query.bindValue(":student_no", studentNo);

    if (query.exec() && query.next()) {
        return createStudentFromQuery(query);
    }
    return std::nullopt;
}

std::optional<Student> StudentDAO::findByUserId(int userId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM students WHERE user_id=:user_id");
    query.bindValue(":user_id", userId);

    if (query.exec() && query.next()) {
        return createStudentFromQuery(query);
    }
    return std::nullopt;
}

QVector<Student> StudentDAO::findByClass(const QString& className)
{
    QVector<Student> students;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM students WHERE class_name=:class_name");
    query.bindValue(":class_name", className);

    if (query.exec()) {
        while (query.next()) {
            students.append(createStudentFromQuery(query));
        }
    }
    return students;
}

QVector<Student> StudentDAO::search(const QString& keyword)
{
    QVector<Student> students;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM students WHERE name LIKE :keyword OR student_no LIKE :keyword");
    query.bindValue(":keyword", "%" + keyword + "%");

    if (query.exec()) {
        while (query.next()) {
            students.append(createStudentFromQuery(query));
        }
    }
    return students;
}

Student StudentDAO::createStudentFromQuery(QSqlQuery& query)
{
    Student student;
    student.setId(query.value("id").toInt());
    student.setUserId(query.value("user_id").toInt());
    student.setStudentNo(query.value("student_no").toString());
    student.setName(query.value("name").toString());
    student.setClassName(query.value("class_name").toString());
    student.setMajor(query.value("major").toString());
    return student;
}
