#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student() = default;

    int id() const { return m_id; }
    void setId(int id) { m_id = id; }

    int userId() const { return m_userId; }
    void setUserId(int userId) { m_userId = userId; }

    QString studentNo() const { return m_studentNo; }
    void setStudentNo(const QString& studentNo) { m_studentNo = studentNo; }

    QString name() const { return m_name; }
    void setName(const QString& name) { m_name = name; }

    QString className() const { return m_className; }
    void setClassName(const QString& className) { m_className = className; }

    QString major() const { return m_major; }
    void setMajor(const QString& major) { m_major = major; }

private:
    int m_id = 0;
    int m_userId = 0;
    QString m_studentNo;
    QString m_name;
    QString m_className;
    QString m_major;
};

#endif // STUDENT_H
