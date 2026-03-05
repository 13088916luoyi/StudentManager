#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include "student.h"

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();

    void setStudent(const Student& student);
    Student getStudent() const;
    void setEditMode(bool edit);

private:
    Ui::StudentDialog *ui;
    bool m_editMode = false;
};

#endif // STUDENTDIALOG_H
