#ifndef COURSESELECTIONDIALOG_H
#define COURSESELECTIONDIALOG_H

#include <QDialog>
#include "course.h"

namespace Ui {
class CourseSelectionDialog;
}

class CourseSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CourseSelectionDialog(QWidget *parent = nullptr);
    ~CourseSelectionDialog();

    void setAvailableCourses(const QVector<Course>& courses);
    int getSelectedCourseId() const;

private:
    Ui::CourseSelectionDialog *ui;
    QVector<Course> m_courses;
};

#endif // COURSESELECTIONDIALOG_H
