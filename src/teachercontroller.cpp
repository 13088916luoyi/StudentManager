#include "teachercontroller.h"

bool TeacherController::addTeacher(const Teacher& teacher)
{
    return m_teacherDAO.insert(teacher);
}

bool TeacherController::updateTeacher(const Teacher& teacher)
{
    return m_teacherDAO.update(teacher);
}

bool TeacherController::deleteTeacher(int id)
{
    return m_teacherDAO.remove(id);
}

QVector<Teacher> TeacherController::getAllTeachers()
{
    return m_teacherDAO.findAll();
}
