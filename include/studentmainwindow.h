#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "user.h"
#include "studentcontroller.h"
#include "gradecontroller.h"
#include "coursecontroller.h"

namespace Ui {
class StudentMainWindow;
}

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainWindow(const User& user, QWidget *parent = nullptr);
    ~StudentMainWindow();

private slots:
    void onNavProfileClicked();
    void onNavCoursesClicked();
    void onNavGradesClicked();
    void onLogoutClicked();
    
    void onEditProfileClicked();
    void onSelectCourseClicked();
    void onDropCourseClicked();
    void onMyCourseTableItemEntered(QTableWidgetItem* item);
    void onAvailableCourseTableItemEntered(QTableWidgetItem* item);
    void onGradeTableItemEntered(QTableWidgetItem* item);

private:
    Ui::StudentMainWindow *ui;
    User m_currentUser;
    StudentController m_studentController;
    GradeController m_gradeController;
    CourseController m_courseController;
    
    int m_studentId = 0;
    Student m_currentStudent;
    
    void loadProfile();
    void loadMyCourses();
    void loadMyGrades();
    void loadAvailableCourses();
    void updateNavButtons(int index);
};

#endif // STUDENTMAINWINDOW_H
