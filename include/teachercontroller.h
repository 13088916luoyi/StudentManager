#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "teacher.h"
#include "teacherdao.h"
#include <QVector>

class TeacherController
{
public:
    TeacherController() = default;

    // 添加教师（带课程关联）
    bool addTeacher(const Teacher& teacher, const QVector<int>& courseIds = QVector<int>());
    // 更新教师（带课程关联）
    bool updateTeacher(const Teacher& teacher, const QVector<int>& courseIds = QVector<int>());
    bool deleteTeacher(int id);
    QVector<Teacher> getAllTeachers();
    QVector<Teacher> searchTeachers(const QString& keyword);

private:
    TeacherDAO m_teacherDAO;
};

#endif // TEACHERCONTROLLER_H
