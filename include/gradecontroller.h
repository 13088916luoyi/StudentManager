#ifndef GRADECONTROLLER_H
#define GRADECONTROLLER_H

#include "grade.h"
#include "gradedao.h"
#include "student.h"
#include "course.h"
#include <QVector>
#include <QMap>

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
    QVector<Grade> searchGrades(const QString& keyword, 
        const QVector<Student>& students, const QVector<Course>& courses);

private:
    GradeDAO m_gradeDAO;
};

#endif // GRADECONTROLLER_H
