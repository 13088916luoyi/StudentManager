#ifndef TEACHERDAO_H
#define TEACHERDAO_H

#include "teacher.h"
#include <QVector>
#include <optional>

class TeacherDAO
{
public:
    TeacherDAO() = default;

    bool insert(const Teacher& teacher);
    bool update(const Teacher& teacher);
    bool remove(int id);
    std::optional<Teacher> findById(int id);
    std::optional<Teacher> findByUserId(int userId);
    std::optional<Teacher> findByTeacherNo(const QString& teacherNo);
    QVector<Teacher> findAll();
    QVector<Teacher> search(const QString& keyword);
    
    // 教师课程关联操作
    QVector<QString> getTeacherCourses(int teacherId);
    bool addTeacherCourse(int teacherId, int courseId);
    bool removeTeacherCourse(int teacherId, int courseId);
    bool clearTeacherCourses(int teacherId);
    bool updateTeacherCourses(int teacherId, const QVector<int>& courseIds);

private:
    Teacher createTeacherFromQuery(class QSqlQuery& query);
};

#endif // TEACHERDAO_H
