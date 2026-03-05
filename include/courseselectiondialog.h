#ifndef COURSESELECTIONDIALOG_H
#define COURSESELECTIONDIALOG_H

#include <QDialog>
#include <QVector>
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

    void setCourses(const QVector<Course>& courses);
    void setSelectedCourseIds(const QVector<int>& courseIds);
    QVector<int> getSelectedCourseIds() const;

private slots:
    void onSelectAllClicked();
    void onDeselectAllClicked();
    void onSelectionChanged();
    void updateSelectedCount();

private:
    Ui::CourseSelectionDialog *ui;
    QVector<Course> m_courses;
};

#endif // COURSESELECTIONDIALOG_H
