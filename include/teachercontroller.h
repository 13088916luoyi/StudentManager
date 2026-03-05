#ifndef TEACHERCONTROLLER_H
#define TEACHERCONTROLLER_H

#include "teacher.h"
#include "teacherdao.h"
#include <QVector>

class TeacherController
{
public:
    TeacherController() = default;

    bool addTeacher(const Teacher& teacher);
    bool updateTeacher(const Teacher& teacher);
    bool deleteTeacher(int id);
    QVector<Teacher> getAllTeachers();

private:
    TeacherDAO m_teacherDAO;
};

#endif // TEACHERCONTROLLER_H
