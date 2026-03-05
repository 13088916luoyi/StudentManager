#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include "teacher.h"

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

private:
    Ui::TeacherDialog *ui;
    bool m_editMode = false;
};

#endif // TEACHERDIALOG_H
