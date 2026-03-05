#include "studentcontroller.h"

bool StudentController::addStudent(const Student& student)
{
    return m_studentDAO.insert(student);
}

bool StudentController::updateStudent(const Student& student)
{
    return m_studentDAO.update(student);
}

bool StudentController::deleteStudent(int id)
{
    return m_studentDAO.remove(id);
}

QVector<Student> StudentController::getAllStudents()
{
    return m_studentDAO.findAll();
}

QVector<Student> StudentController::searchStudents(const QString& keyword)
{
    return m_studentDAO.search(keyword);
}

std::optional<Student> StudentController::getStudentById(int id)
{
    return m_studentDAO.findById(id);
}
