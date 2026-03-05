#ifndef COURSECONTROLLER_H
#define COURSECONTROLLER_H

#include "course.h"
#include "coursedao.h"
#include <QVector>

class CourseController
{
public:
    CourseController() = default;

    bool addCourse(const Course& course);
    bool updateCourse(const Course& course);
    bool deleteCourse(int id);
    QVector<Course> getAllCourses();
    QVector<Course> searchCourses(const QString& keyword);
    QVector<Course> getCoursesByTeacher(int teacherId);

private:
    CourseDAO m_courseDAO;
};

#endif // COURSECONTROLLER_H
