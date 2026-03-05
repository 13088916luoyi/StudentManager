#include "coursedao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool CourseDAO::insert(const Course& course)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO courses (course_no, course_name, credit, hours, course_type) "
                  "VALUES (:course_no, :course_name, :credit, :hours, :course_type)");
    query.bindValue(":course_no", course.courseNo());
    query.bindValue(":course_name", course.courseName());
    query.bindValue(":credit", course.credit());
    query.bindValue(":hours", course.hours());
    query.bindValue(":course_type", course.courseType());

    if (!query.exec()) {
        qDebug() << "插入课程失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CourseDAO::update(const Course& course)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE courses SET course_no=:course_no, course_name=:course_name, "
                  "credit=:credit, hours=:hours, course_type=:course_type WHERE id=:id");
    query.bindValue(":course_no", course.courseNo());
    query.bindValue(":course_name", course.courseName());
    query.bindValue(":credit", course.credit());
    query.bindValue(":hours", course.hours());
    query.bindValue(":course_type", course.courseType());
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

std::optional<Course> CourseDAO::findByCourseNo(const QString& courseNo)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM courses WHERE course_no=:course_no");
    query.bindValue(":course_no", courseNo);

    if (query.exec() && query.next()) {
        return createCourseFromQuery(query);
    }
    return std::nullopt;
}

QVector<Course> CourseDAO::search(const QString& keyword)
{
    QVector<Course> courses;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM courses WHERE course_name LIKE :keyword OR course_no LIKE :keyword");
    query.bindValue(":keyword", "%" + keyword + "%");

    if (query.exec()) {
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
    query.prepare("SELECT c.* FROM courses c "
                  "INNER JOIN teacher_courses tc ON c.id = tc.course_id "
                  "WHERE tc.teacher_id = :teacher_id");
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
    course.setCredit(query.value("credit").toDouble());
    course.setHours(query.value("hours").toInt());
    course.setCourseType(query.value("course_type").toString());
    return course;
}
