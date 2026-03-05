#ifndef GRADEDAO_H
#define GRADEDAO_H

#include "grade.h"
#include <QVector>
#include <optional>

class GradeDAO
{
public:
    GradeDAO() = default;

    bool insert(const Grade& grade);
    bool update(const Grade& grade);
    bool remove(int id);
    std::optional<Grade> findById(int id);
    QVector<Grade> findAll();
    QVector<Grade> findByStudentId(int studentId);
    QVector<Grade> findByCourseId(int courseId);

private:
    Grade createGradeFromQuery(class QSqlQuery& query);
};

#endif // GRADEDAO_H
