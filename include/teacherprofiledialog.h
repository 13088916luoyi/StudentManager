#ifndef TEACHERPROFILEDIALOG_H
#define TEACHERPROFILEDIALOG_H

#include <QDialog>
#include "teacher.h"

namespace Ui {
class TeacherProfileDialog;
}

class TeacherProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherProfileDialog(QWidget *parent = nullptr);
    ~TeacherProfileDialog();

    void setTeacher(const Teacher& teacher);
    Teacher getTeacher() const;

private:
    Ui::TeacherProfileDialog *ui;
    Teacher m_teacher;
};

#endif // TEACHERPROFILEDIALOG_H
