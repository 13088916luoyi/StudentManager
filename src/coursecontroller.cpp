#include "coursecontroller.h"

bool CourseController::addCourse(const Course& course)
{
    return m_courseDAO.insert(course);
}

bool CourseController::updateCourse(const Course& course)
{
    return m_courseDAO.update(course);
}

bool CourseController::deleteCourse(int id)
{
    return m_courseDAO.remove(id);
}

QVector<Course> CourseController::getAllCourses()
{
    return m_courseDAO.findAll();
}

QVector<Course> CourseController::searchCourses(const QString& keyword)
{
    return m_courseDAO.search(keyword);
}

QVector<Course> CourseController::getCoursesByTeacher(int teacherId)
{
    return m_courseDAO.findByTeacherId(teacherId);
}
