#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>
#include "course.h"
#include "teacher.h"
#include <QVector>

namespace Ui {
class CourseDialog;
}

class CourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CourseDialog(QWidget *parent = nullptr);
    ~CourseDialog();

    void setCourse(const Course& course);
    Course getCourse() const;
    void setEditMode(bool edit);
    void setTeachers(const QVector<Teacher>& teachers);

private:
    Ui::CourseDialog *ui;
    bool m_editMode = false;
};

#endif // COURSEDIALOG_H
