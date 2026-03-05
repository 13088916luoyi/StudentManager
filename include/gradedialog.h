#ifndef GRADEDIALOG_H
#define GRADEDIALOG_H

#include <QDialog>
#include "grade.h"
#include "student.h"
#include "course.h"
#include <QVector>

namespace Ui {
class GradeDialog;
}

class GradeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradeDialog(QWidget *parent = nullptr);
    ~GradeDialog();

    void setGrade(const Grade& grade);
    Grade getGrade() const;
    void setEditMode(bool edit);
    void setStudents(const QVector<Student>& students);
    void setCourses(const QVector<Course>& courses);

private:
    Ui::GradeDialog *ui;
    bool m_editMode = false;
};

#endif // GRADEDIALOG_H
