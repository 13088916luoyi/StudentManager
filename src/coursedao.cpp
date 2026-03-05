#include "coursedao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool CourseDAO::insert(const Course& course)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO courses (course_no, course_name, teacher_id, credit, hours, description) "
                  "VALUES (:course_no, :course_name, :teacher_id, :credit, :hours, :description)");
    query.bindValue(":course_no", course.courseNo());
    query.bindValue(":course_name", course.courseName());
    query.bindValue(":teacher_id", course.teacherId() == 0 ? QVariant() : course.teacherId());
    query.bindValue(":credit", course.credit());
    query.bindValue(":hours", course.hours());
    query.bindValue(":description", course.description());

    if (!query.exec()) {
        qDebug() << "插入课程失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CourseDAO::update(const Course& course)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE courses SET course_no=:course_no, course_name=:course_name, teacher_id=:teacher_id, "
                  "credit=:credit, hours=:hours, description=:description WHERE id=:id");
    query.bindValue(":course_no", course.courseNo());
    query.bindValue(":course_name", course.courseName());
    query.bindValue(":teacher_id", course.teacherId() == 0 ? QVariant() : course.teacherId());
    query.bindValue(":credit", course.credit());
    query.bindValue(":hours", course.hours());
    query.bindValue(":description", course.description());
    query.bindValue(":id", course.id());

    if (!query.exec()) {
        qDebug() << "更新课程失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CourseDAO::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM courses WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "删除课程失败:" << query.lastError().text();
        return false;
    }
    return true;
}

std::optional<Course> CourseDAO::findById(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM courses WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return createCourseFromQuery(query);
    }
    return std::nullopt;
}

QVector<Course> CourseDAO::findAll()
{
    QVector<Course> courses;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM courses")) {
        while (query.next()) {
            courses.append(createCourseFromQuery(query));
        }
    }
    return courses;
}

QVector<Course> CourseDAO::findByTeacherId(int teacherId)
{
    QVector<Course> courses;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM courses WHERE teacher_id=:teacher_id");
    query.bindValue(":teacher_id", teacherId);

    if (query.exec()) {
        while (query.next()) {
            courses.append(createCourseFromQuery(query));
        }
    }
    return courses;
}

Course CourseDAO::createCourseFromQuery(QSqlQuery& query)
{
    Course course;
    course.setId(query.value("id").toInt());
    course.setCourseNo(query.value("course_no").toString());
    course.setCourseName(query.value("course_name").toString());
    course.setTeacherId(query.value("teacher_id").toInt());
    course.setCredit(query.value("credit").toDouble());
    course.setHours(query.value("hours").toInt());
    course.setDescription(query.value("description").toString());
    return course;
}
