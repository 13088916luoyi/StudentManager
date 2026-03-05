#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include <QVector>
#include "teacher.h"
#include "course.h"

namespace Ui {
class TeacherDialog;
}

class TeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherDialog(QWidget *parent = nullptr);
    ~TeacherDialog();

    void setTeacher(const Teacher& teacher);
    Teacher getTeacher() const;
    void setEditMode(bool edit);
    
    // 设置可选课程列表
    void setAvailableCourses(const QVector<Course>& courses);
    
    // 获取选中的课程ID列表
    QVector<int> getSelectedCourseIds() const;

private slots:
    void onSelectCoursesClicked();

private:
    Ui::TeacherDialog *ui;
    bool m_editMode = false;
    QVector<Course> m_availableCourses;
    QVector<int> m_selectedCourseIds;
    
    void updateCoursesDisplay();
};

#endif // TEACHERDIALOG_H
