#include "gradedao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool GradeDAO::insert(const Grade& grade)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO grades (student_id, course_id, grade, semester, exam_type, remarks) "
                  "VALUES (:student_id, :course_id, :grade, :semester, :exam_type, :remarks)");
    query.bindValue(":student_id", grade.studentId());
    query.bindValue(":course_id", grade.courseId());
    query.bindValue(":grade", grade.grade());
    query.bindValue(":semester", grade.semester());
    query.bindValue(":exam_type", grade.examType());
    query.bindValue(":remarks", grade.remarks());

    if (!query.exec()) {
        qDebug() << "插入成绩失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool GradeDAO::update(const Grade& grade)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE grades SET student_id=:student_id, course_id=:course_id, grade=:grade, "
                  "semester=:semester, exam_type=:exam_type, remarks=:remarks WHERE id=:id");
    query.bindValue(":student_id", grade.studentId());
    query.bindValue(":course_id", grade.courseId());
    query.bindValue(":grade", grade.grade());
    query.bindValue(":semester", grade.semester());
    query.bindValue(":exam_type", grade.examType());
    query.bindValue(":remarks", grade.remarks());
    query.bindValue(":id", grade.id());

    if (!query.exec()) {
        qDebug() << "更新成绩失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool GradeDAO::remove(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM grades WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "删除成绩失败:" << query.lastError().text();
        return false;
    }
    return true;
}

std::optional<Grade> GradeDAO::findById(int id)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM grades WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return createGradeFromQuery(query);
    }
    return std::nullopt;
}

QVector<Grade> GradeDAO::findAll()
{
    QVector<Grade> grades;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM grades")) {
        while (query.next()) {
            grades.append(createGradeFromQuery(query));
        }
    }
    return grades;
}

QVector<Grade> GradeDAO::findByStudentId(int studentId)
{
    QVector<Grade> grades;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM grades WHERE student_id=:student_id");
    query.bindValue(":student_id", studentId);

    if (query.exec()) {
        while (query.next()) {
            grades.append(createGradeFromQuery(query));
        }
    }
    return grades;
}

QVector<Grade> GradeDAO::findByCourseId(int courseId)
{
    QVector<Grade> grades;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM grades WHERE course_id=:course_id");
    query.bindValue(":course_id", courseId);

    if (query.exec()) {
        while (query.next()) {
            grades.append(createGradeFromQuery(query));
        }
    }
    return grades;
}

Grade GradeDAO::createGradeFromQuery(QSqlQuery& query)
{
    Grade grade;
    grade.setId(query.value("id").toInt());
    grade.setStudentId(query.value("student_id").toInt());
    grade.setCourseId(query.value("course_id").toInt());
    grade.setGrade(query.value("grade").toDouble());
    grade.setSemester(query.value("semester").toString());
    grade.setExamType(query.value("exam_type").toString());
    grade.setRemarks(query.value("remarks").toString());
    return grade;
}
