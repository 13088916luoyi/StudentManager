#ifndef GRADE_H
#define GRADE_H

#include <QString>

class Grade
{
public:
    Grade() = default;

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    int studentId() const { return m_studentId; }
    void setStudentId(int studentId) { m_studentId = studentId; }

    int courseId() const { return m_courseId; }
    void setCourseId(int courseId) { m_courseId = courseId; }

    double grade() const { return m_grade; }
    void setGrade(double grade) { m_grade = grade; }

private:
    int m_id = 0;
    int m_studentId = 0;
    int m_courseId = 0;
    double m_grade = 0.0;
};

#endif // GRADE_H
