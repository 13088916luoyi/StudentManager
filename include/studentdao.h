#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include "student.h"
#include <QVector>
#include <optional>

class StudentDAO
{
public:
    StudentDAO() = default;

    bool insert(const Student& student);
    bool update(const Student& student);
    bool remove(int id);
    std::optional<Student> findById(int id);
    QVector<Student> findAll();
    std::optional<Student> findByStudentNo(const QString& studentNo);
    std::optional<Student> findByUserId(int userId);
    QVector<Student> findByClass(const QString& className);
    QVector<Student> search(const QString& keyword);

private:
    Student createStudentFromQuery(class QSqlQuery& query);
};

#endif // STUDENTDAO_H
