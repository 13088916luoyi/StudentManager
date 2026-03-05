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

    QString semester() const { return m_semester; }
    void setSemester(const QString& semester) { m_semester = semester; }

    QString examType() const { return m_examType; }
    void setExamType(const QString& examType) { m_examType = examType; }

    QString remarks() const { return m_remarks; }
    void setRemarks(const QString& remarks) { m_remarks = remarks; }

private:
    int m_id = 0;
    int m_studentId = 0;
    int m_courseId = 0;
    double m_grade = 0.0;
    QString m_semester;
    QString m_examType;
    QString m_remarks;
};

#endif // GRADE_H
