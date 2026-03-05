#ifndef TEACHERDAO_H
#define TEACHERDAO_H

#include "teacher.h"
#include <QVector>
#include <optional>

class TeacherDAO
{
public:
    TeacherDAO() = default;

    bool insert(const Teacher& teacher);
    bool update(const Teacher& teacher);
    bool remove(int id);
    std::optional<Teacher> findById(int id);
    std::optional<Teacher> findByUserId(int userId);
    QVector<Teacher> findAll();

private:
    Teacher createTeacherFromQuery(class QSqlQuery& query);
};

#endif // TEACHERDAO_H
