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

    QString gender() const { return m_gender; }
    void setGender(const QString& gender) { m_gender = gender; }

    int age() const { return m_age; }
    void setAge(int age) { m_age = age; }

    QString department() const { return m_department; }
    void setDepartment(const QString& department) { m_department = department; }

    QString className() const { return m_className; }
    void setClassName(const QString& className) { m_className = className; }

    QString phone() const { return m_phone; }
    void setPhone(const QString& phone) { m_phone = phone; }

    QString email() const { return m_email; }
    void setEmail(const QString& email) { m_email = email; }

private:
    int m_id = 0;
    int m_userId = 0;
    QString m_studentNo;
    QString m_name;
    QString m_gender;
    int m_age = 0;
    QString m_department;
    QString m_className;
    QString m_phone;
    QString m_email;
};

#endif // STUDENT_H
