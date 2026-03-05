#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
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
    void onSearchTeacherChanged(const QString& text);

    void onAddCourseClicked();
    void onEditCourseClicked();
    void onDeleteCourseClicked();
    void onRefreshCoursesClicked();
    void onSearchCourseChanged(const QString& text);

    void onAddGradeClicked();
    void onEditGradeClicked();
    void onDeleteGradeClicked();
    void onRefreshGradesClicked();
    void onSearchGradeChanged(const QString& text);

    void onStudentTableItemEntered(QTableWidgetItem* item);
    void onTeacherTableItemEntered(QTableWidgetItem* item);
    void onCourseTableItemEntered(QTableWidgetItem* item);
    void onGradeTableItemEntered(QTableWidgetItem* item);
    void onAccountTableItemEntered(QTableWidgetItem* item);

    void onAddAccountClicked();
    void onEditAccountClicked();
    void onDeleteAccountClicked();
    void onRefreshAccountsClicked();
    void onSearchAccountChanged(const QString& text);

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
    void setupAccountPage();
    void updateNavButtons(int index);
};

#endif // ADMINMAINWINDOW_H
