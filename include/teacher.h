#ifndef TEACHER_H
#define TEACHER_H

#include <QString>
#include <QStringList>

class Teacher
{
public:
    Teacher() = default;

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    int userId() const { return m_userId; }
    void setUserId(int userId) { m_userId = userId; }

    QString teacherNo() const { return m_teacherNo; }
    void setTeacherNo(const QString& teacherNo) { m_teacherNo = teacherNo; }

    QString name() const { return m_name; }
    void setName(const QString& name) { m_name = name; }

    // 教授的课程列表（课程名称列表）
    QStringList courses() const { return m_courses; }
    void setCourses(const QStringList& courses) { m_courses = courses; }
    void addCourse(const QString& course) { m_courses.append(course); }
    void removeCourse(const QString& course) { m_courses.removeAll(course); }
    QString coursesString() const { return m_courses.join(", "); }

private:
    int m_id = 0;
    int m_userId = 0;
    QString m_teacherNo;
    QString m_name;
    QStringList m_courses;  // 教授的课程列表
};

#endif // TEACHER_H
