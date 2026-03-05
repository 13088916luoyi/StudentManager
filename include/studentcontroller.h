#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "student.h"
#include "studentdao.h"
#include <QVector>

class StudentController
{
public:
    StudentController() = default;

    bool addStudent(const Student& student);
    bool updateStudent(const Student& student);
    bool deleteStudent(int id);
    QVector<Student> getAllStudents();
    QVector<Student> searchStudents(const QString& keyword);
    std::optional<Student> getStudentById(int id);

private:
    StudentDAO m_studentDAO;
};

#endif // STUDENTCONTROLLER_H
