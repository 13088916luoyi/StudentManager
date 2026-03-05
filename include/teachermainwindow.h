#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "teachercontroller.h"
#include "coursecontroller.h"
#include "gradecontroller.h"
#include "studentcontroller.h"

namespace Ui {
class TeacherMainWindow;
}

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(const User& user, QWidget *parent = nullptr);
    ~TeacherMainWindow();

private slots:
    void onNavProfileClicked();
    void onNavCoursesClicked();
    void onLogoutClicked();
    
    void onEditProfileClicked();
    
    void onCourseDoubleClicked(int row, int column);
    void onEditGradeClicked();
    void onViewStatsClicked();

private:
    Ui::TeacherMainWindow *ui;
    User m_currentUser;
    TeacherController m_teacherController;
    CourseController m_courseController;
    GradeController m_gradeController;
    StudentController m_studentController;
    
    int m_teacherId = 0;
    Teacher m_currentTeacher;
    int m_currentCourseId = 0;
    QString m_currentCourseName;
    QVector<int> m_currentGrades;
    
    void loadProfile();
    void loadMyCourses();
    void loadCourseStudents(int courseId);
    void updateNavButtons(int index);
};

#endif // TEACHERMAINWINDOW_H
