#ifndef COURSEDAO_H
#define COURSEDAO_H

#include "course.h"
#include <QVector>
#include <optional>

class CourseDAO
{
public:
    CourseDAO() = default;

    bool insert(const Course& course);
    bool update(const Course& course);
    bool remove(int id);
    std::optional<Course> findById(int id);
    std::optional<Course> findByCourseNo(const QString& courseNo);
    QVector<Course> findAll();
    QVector<Course> search(const QString& keyword);
    QVector<Course> findByTeacherId(int teacherId);

private:
    Course createCourseFromQuery(class QSqlQuery& query);
};

#endif // COURSEDAO_H
