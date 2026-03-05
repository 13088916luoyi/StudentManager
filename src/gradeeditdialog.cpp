#include "gradeeditdialog.h"
#include "ui_gradeeditdialog.h"

GradeEditDialog::GradeEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradeEditDialog)
{
    ui->setupUi(this);
    setWindowTitle("修改成绩");
}

GradeEditDialog::~GradeEditDialog()
{
    delete ui;
}

void GradeEditDialog::setStudentInfo(const QString& studentNo, const QString& studentName)
{
    ui->studentNoLabel->setText(studentNo);
    ui->studentNameLabel->setText(studentName);
}

void GradeEditDialog::setGrade(int grade)
{
    ui->gradeSpinBox->setValue(grade);
}

int GradeEditDialog::getGrade() const
{
    return ui->gradeSpinBox->value();
}
