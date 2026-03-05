#ifndef GRADECONTROLLER_H
#define GRADECONTROLLER_H

#include "grade.h"
#include "gradedao.h"
#include <QVector>

class GradeController
{
public:
    GradeController() = default;

    bool addGrade(const Grade& grade);
    bool updateGrade(const Grade& grade);
    bool deleteGrade(int id);
    QVector<Grade> getAllGrades();
    QVector<Grade> getGradesByStudent(int studentId);
    QVector<Grade> getGradesByCourse(int courseId);

private:
    GradeDAO m_gradeDAO;
};

#endif // GRADECONTROLLER_H
