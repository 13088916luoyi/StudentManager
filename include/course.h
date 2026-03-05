#ifndef COURSE_H
#define COURSE_H

#include <QString>

class Course
{
public:
    Course() = default;

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    QString courseNo() const { return m_courseNo; }
    void setCourseNo(const QString& courseNo) { m_courseNo = courseNo; }

    QString courseName() const { return m_courseName; }
    void setCourseName(const QString& courseName) { m_courseName = courseName; }

    int teacherId() const { return m_teacherId; }
    void setTeacherId(int teacherId) { m_teacherId = teacherId; }

    double credit() const { return m_credit; }
    void setCredit(double credit) { m_credit = credit; }

    int hours() const { return m_hours; }
    void setHours(int hours) { m_hours = hours; }

    QString description() const { return m_description; }
    void setDescription(const QString& description) { m_description = description; }

private:
    int m_id = 0;
    QString m_courseNo;
    QString m_courseName;
    int m_teacherId = 0;
    double m_credit = 0.0;
    int m_hours = 0;
    QString m_description;
};

#endif // COURSE_H
