#include "gradecontroller.h"

bool GradeController::addGrade(const Grade& grade)
{
    return m_gradeDAO.insert(grade);
}

bool GradeController::updateGrade(const Grade& grade)
{
    return m_gradeDAO.update(grade);
}

bool GradeController::deleteGrade(int id)
{
    return m_gradeDAO.remove(id);
}

QVector<Grade> GradeController::getAllGrades()
{
    return m_gradeDAO.findAll();
}

QVector<Grade> GradeController::getGradesByStudent(int studentId)
{
    return m_gradeDAO.findByStudentId(studentId);
}

QVector<Grade> GradeController::getGradesByCourse(int courseId)
{
    return m_gradeDAO.findByCourseId(courseId);
}

QVector<Grade> GradeController::searchGrades(const QString& keyword, 
    const QVector<Student>& students, const QVector<Course>& courses)
{
    QVector<Grade> allGrades = m_gradeDAO.findAll();
    if (keyword.isEmpty()) {
        return allGrades;
    }

    // 构建学生和课程的查找映射
    QMap<int, Student> studentMap;
    QMap<int, Course> courseMap;
    for (const Student& s : students) {
        studentMap[s.id()] = s;
    }
    for (const Course& c : courses) {
        courseMap[c.id()] = c;
    }

    QVector<Grade> result;
    for (const Grade& grade : allGrades) {
        bool match = false;
        
        // 检查学生信息
        if (studentMap.contains(grade.studentId())) {
            const Student& s = studentMap[grade.studentId()];
            if (s.name().contains(keyword, Qt::CaseInsensitive) ||
                s.studentNo().contains(keyword, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        
        // 检查课程信息
        if (!match && courseMap.contains(grade.courseId())) {
            const Course& c = courseMap[grade.courseId()];
            if (c.courseName().contains(keyword, Qt::CaseInsensitive) ||
                c.courseNo().contains(keyword, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        
        if (match) {
            result.append(grade);
        }
    }
    return result;
}
