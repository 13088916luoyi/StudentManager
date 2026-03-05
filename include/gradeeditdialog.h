#ifndef GRADEEDITDIALOG_H
#define GRADEEDITDIALOG_H

#include <QDialog>

namespace Ui {
class GradeEditDialog;
}

class GradeEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradeEditDialog(QWidget *parent = nullptr);
    ~GradeEditDialog();

    void setStudentInfo(const QString& studentNo, const QString& studentName);
    void setGrade(int grade);
    int getGrade() const;

private:
    Ui::GradeEditDialog *ui;
};

#endif // GRADEEDITDIALOG_H
