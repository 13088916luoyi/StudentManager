#include "teacherdao.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool TeacherDAO::insert(const Teacher& teacher)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO teachers (user_id, teacher_no, name) "
                  "VALUES (:user_id, :teacher_no, :name)");
    query.bindValue(":user_id", teacher.userId() == 0 ? QVariant() : teacher.userId());
    query.bindValue(":teacher_no", teacher.teacherNo());
    query.bindValue(":name", teacher.name());

    if (!query.exec()) {
        qDebug() << "插入教师失败:" << query.lastError().text();
        return false;
    }
    return true;
}

bool TeacherDAO::update(const Teacher& teacher)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("UPDATE teachers SET user_id=:user_id, teacher_no=:teacher_no, name=:name WHERE id=:id");
    query.bindValue(":user_id", teacher.userId() == 0 ? QVariant() : teacher.userId());
    query.bindValue(":teacher_no", teacher.teacherNo());
    query.bindValue(":name", teacher.name());
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
        Teacher teacher = createTeacherFromQuery(query);
        // 加载教师教授的课程
        teacher.setCourses(getTeacherCourses(id));
        return teacher;
    }
    return std::nullopt;
}

std::optional<Teacher> TeacherDAO::findByUserId(int userId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM teachers WHERE user_id=:user_id");
    query.bindValue(":user_id", userId);

    if (query.exec() && query.next()) {
        Teacher teacher = createTeacherFromQuery(query);
        // 加载教师教授的课程
        teacher.setCourses(getTeacherCourses(teacher.id()));
        return teacher;
    }
    return std::nullopt;
}

QVector<Teacher> TeacherDAO::findAll()
{
    QVector<Teacher> teachers;
    QSqlQuery query(DatabaseManager::instance().database());

    if (query.exec("SELECT * FROM teachers")) {
        while (query.next()) {
            Teacher teacher = createTeacherFromQuery(query);
            // 加载教师教授的课程
            teacher.setCourses(getTeacherCourses(teacher.id()));
            teachers.append(teacher);
        }
    }
    return teachers;
}

std::optional<Teacher> TeacherDAO::findByTeacherNo(const QString& teacherNo)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM teachers WHERE teacher_no=:teacher_no");
    query.bindValue(":teacher_no", teacherNo);

    if (query.exec() && query.next()) {
        Teacher teacher = createTeacherFromQuery(query);
        // 加载教师教授的课程
        teacher.setCourses(getTeacherCourses(teacher.id()));
        return teacher;
    }
    return std::nullopt;
}

QVector<Teacher> TeacherDAO::search(const QString& keyword)
{
    QVector<Teacher> teachers;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT * FROM teachers WHERE name LIKE :keyword OR teacher_no LIKE :keyword");
    query.bindValue(":keyword", "%" + keyword + "%");

    if (query.exec()) {
        while (query.next()) {
            Teacher teacher = createTeacherFromQuery(query);
            // 加载教师教授的课程
            teacher.setCourses(getTeacherCourses(teacher.id()));
            teachers.append(teacher);
        }
    }
    return teachers;
}

// 获取教师教授的课程名称列表
QVector<QString> TeacherDAO::getTeacherCourses(int teacherId)
{
    QVector<QString> courses;
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("SELECT c.course_name FROM courses c "
                  "INNER JOIN teacher_courses tc ON c.id = tc.course_id "
                  "WHERE tc.teacher_id = :teacher_id");
    query.bindValue(":teacher_id", teacherId);

    if (query.exec()) {
        while (query.next()) {
            courses.append(query.value(0).toString());
        }
    }
    return courses;
}

// 添加教师-课程关联
bool TeacherDAO::addTeacherCourse(int teacherId, int courseId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("INSERT INTO teacher_courses (teacher_id, course_id) VALUES (:teacher_id, :course_id)");
    query.bindValue(":teacher_id", teacherId);
    query.bindValue(":course_id", courseId);

    if (!query.exec()) {
        qDebug() << "添加教师课程关联失败:" << query.lastError().text();
        return false;
    }
    return true;
}

// 删除教师-课程关联
bool TeacherDAO::removeTeacherCourse(int teacherId, int courseId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM teacher_courses WHERE teacher_id=:teacher_id AND course_id=:course_id");
    query.bindValue(":teacher_id", teacherId);
    query.bindValue(":course_id", courseId);

    if (!query.exec()) {
        qDebug() << "删除教师课程关联失败:" << query.lastError().text();
        return false;
    }
    return true;
}

// 清除教师的所有课程关联
bool TeacherDAO::clearTeacherCourses(int teacherId)
{
    QSqlQuery query(DatabaseManager::instance().database());
    query.prepare("DELETE FROM teacher_courses WHERE teacher_id=:teacher_id");
    query.bindValue(":teacher_id", teacherId);

    if (!query.exec()) {
        qDebug() << "清除教师课程关联失败:" << query.lastError().text();
        return false;
    }
    return true;
}

// 更新教师的课程关联（先清除再添加）
bool TeacherDAO::updateTeacherCourses(int teacherId, const QVector<int>& courseIds)
{
    // 先清除所有关联
    if (!clearTeacherCourses(teacherId)) {
        return false;
    }

    // 添加新的关联
    for (int courseId : courseIds) {
        if (!addTeacherCourse(teacherId, courseId)) {
            return false;
        }
    }
    return true;
}

Teacher TeacherDAO::createTeacherFromQuery(QSqlQuery& query)
{
    Teacher teacher;
    teacher.setId(query.value("id").toInt());
    teacher.setUserId(query.value("user_id").toInt());
    teacher.setTeacherNo(query.value("teacher_no").toString());
    teacher.setName(query.value("name").toString());
    return teacher;
}
