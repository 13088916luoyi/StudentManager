#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "studentcontroller.h"
#include "teachercontroller.h"
#include "coursecontroller.h"
#include "gradecontroller.h"

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(const User& user, QWidget *parent = nullptr);
    ~AdminMainWindow();

private slots:
    void onNavStudentClicked();
    void onNavTeacherClicked();
    void onNavCourseClicked();
    void onNavGradeClicked();
    void onNavAccountClicked();
    void onLogoutClicked();

    void onAddStudentClicked();
    void onEditStudentClicked();
    void onDeleteStudentClicked();
    void onRefreshStudentsClicked();
    void onSearchStudentChanged(const QString& text);

    void onAddTeacherClicked();
    void onEditTeacherClicked();
    void onDeleteTeacherClicked();
    void onRefreshTeachersClicked();

    void onAddCourseClicked();
    void onEditCourseClicked();
    void onDeleteCourseClicked();
    void onRefreshCoursesClicked();

    void onAddGradeClicked();
    void onEditGradeClicked();
    void onDeleteGradeClicked();
    void onRefreshGradesClicked();

private:
    Ui::AdminMainWindow *ui;
    User m_currentUser;
    StudentController m_studentController;
    TeacherController m_teacherController;
    CourseController m_courseController;
    GradeController m_gradeController;

    void loadStudents();
    void loadTeachers();
    void loadCourses();
    void loadGrades();
    void loadAccounts();
    
    void setupStudentPage();
    void setupTeacherPage();
    void setupCoursePage();
    void setupGradePage();
    void updateNavButtons(int index);
};

#endif // ADMINMAINWINDOW_H
