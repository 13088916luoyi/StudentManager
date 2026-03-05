#include "teacherdao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool TeacherDAO::insert(const Teacher& teacher)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO teachers (user_id, teacher_no, name, gender, age, department, title, phone, email) "
                  "VALUES (:user_id, :teacher_no, :name, :gender, :age, :department, :title, :phone, :email)");
    query.bindValue(":user_id", teacher.userId() == 0 ? QVariant() : teacher.userId());
    query.bindValue(":teacher_no", teacher.teacherNo());
    query.bindValue(":name", teacher.name());
    query.bindValue(":gender", teacher.gender());
    query.bindValue(":age", teacher.age());
    query.bindValue(":department", teacher.department());
    query.bindValue(":title", teacher.title());
    query.bindValue(":phone", teacher.phone());
    query.bindValue(":email", teacher.email());

    if (!query.exec()) {
        qDebug() << "插入教师失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool TeacherDAO::update(const Teacher& teacher)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE teachers SET user_id=:user_id, teacher_no=:teacher_no, name=:name, gender=:gender, "
                  "age=:age, department=:department, title=:title, phone=:phone, email=:email WHERE id=:id");
    query.bindValue(":user_id", teacher.userId() == 0 ? QVariant() : teacher.userId());
    query.bindValue(":teacher_no", teacher.teacherNo());
    query.bindValue(":name", teacher.name());
    query.bindValue(":gender", teacher.gender());
    query.bindValue(":age", teacher.age());
    query.bindValue(":department", teacher.department());
    query.bindValue(":title", teacher.title());
    query.bindValue(":phone", teacher.phone());
    query.bindValue(":email", teacher.email());
    query.bindValue(":id", teacher.id());

    if (!query.exec()) {
        qDebug() << "更新教师失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool TeacherDAO::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM teachers WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "删除教师失败:" << query.lastError().text();
        return false;
    }
    return true;
}

std::optional<Teacher> TeacherDAO::findById(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM teachers WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return createTeacherFromQuery(query);
    }
    return std::nullopt;
}

std::optional<Teacher> TeacherDAO::findByUserId(int userId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM teachers WHERE user_id=:user_id");
    query.bindValue(":user_id", userId);

    if (query.exec() && query.next()) {
        return createTeacherFromQuery(query);
    }
    return std::nullopt;
}

QVector<Teacher> TeacherDAO::findAll()
{
    QVector<Teacher> teachers;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM teachers")) {
        while (query.next()) {
            teachers.append(createTeacherFromQuery(query));
        }
    }
    return teachers;
}

Teacher TeacherDAO::createTeacherFromQuery(QSqlQuery& query)
{
    Teacher teacher;
    teacher.setId(query.value("id").toInt());
    teacher.setUserId(query.value("user_id").toInt());
    teacher.setTeacherNo(query.value("teacher_no").toString());
    teacher.setName(query.value("name").toString());
    teacher.setGender(query.value("gender").toString());
    teacher.setAge(query.value("age").toInt());
    teacher.setDepartment(query.value("department").toString());
    teacher.setTitle(query.value("title").toString());
    teacher.setPhone(query.value("phone").toString());
    teacher.setEmail(query.value("email").toString());
    return teacher;
}
