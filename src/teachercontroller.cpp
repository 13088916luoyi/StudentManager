#include "teachercontroller.h"

bool TeacherController::addTeacher(const Teacher& teacher, const QVector<int>& courseIds)
{
    // 先插入教师基本信息
    if (!m_teacherDAO.insert(teacher)) {
        return false;
    }
    
    // 如果有课程关联，需要获取刚插入的教师ID
    if (!courseIds.isEmpty()) {
        // 通过工号查找刚插入的教师
        auto teacherOpt = m_teacherDAO.findByTeacherNo(teacher.teacherNo());
        if (teacherOpt.has_value()) {
            int teacherId = teacherOpt.value().id();
            // 建立课程关联
            return m_teacherDAO.updateTeacherCourses(teacherId, courseIds);
        }
    }
    
    return true;
}

bool TeacherController::updateTeacher(const Teacher& teacher, const QVector<int>& courseIds)
{
    // 先更新教师基本信息
    if (!m_teacherDAO.update(teacher)) {
        return false;
    }
    
    // 更新课程关联
    if (!courseIds.isEmpty()) {
        return m_teacherDAO.updateTeacherCourses(teacher.id(), courseIds);
    }
    
    return true;
}

bool TeacherController::deleteTeacher(int id)
{
    return m_teacherDAO.remove(id);
}

QVector<Teacher> TeacherController::getAllTeachers()
{
    return m_teacherDAO.findAll();
}

QVector<Teacher> TeacherController::searchTeachers(const QString& keyword)
{
    return m_teacherDAO.search(keyword);
}
