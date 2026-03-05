#ifndef STUDENTPROFILEDIALOG_H
#define STUDENTPROFILEDIALOG_H

#include <QDialog>
#include "student.h"

namespace Ui {
class StudentProfileDialog;
}

class StudentProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentProfileDialog(QWidget *parent = nullptr);
    ~StudentProfileDialog();

    void setStudent(const Student& student);
    Student getStudent() const;

private:
    Ui::StudentProfileDialog *ui;
    Student m_student;
};

#endif // STUDENTPROFILEDIALOG_H
