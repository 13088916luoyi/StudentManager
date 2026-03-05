#include "gradecontroller.h"

bool GradeController::addGrade(const Grade& grade)
{
    return m_gradeDAO.insert(grade);
}

bool GradeController::updateGrade(const Grade& grade)
{
    return m_gradeDAO.update(grade);
}

bool GradeController::deleteGrade(int id)
{
    return m_gradeDAO.remove(id);
}

QVector<Grade> GradeController::getAllGrades()
{
    return m_gradeDAO.findAll();
}

QVector<Grade> GradeController::getGradesByStudent(int studentId)
{
    return m_gradeDAO.findByStudentId(studentId);
}

QVector<Grade> GradeController::getGradesByCourse(int courseId)
{
    return m_gradeDAO.findByCourseId(courseId);
}
