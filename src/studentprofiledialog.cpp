#include "studentprofiledialog.h"
#include "ui_studentprofiledialog.h"

StudentProfileDialog::StudentProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentProfileDialog)
{
    ui->setupUi(this);
    setWindowTitle("编辑个人信息");
}

StudentProfileDialog::~StudentProfileDialog()
{
    delete ui;
}

void StudentProfileDialog::setStudent(const Student& student)
{
    m_student = student;

    ui->studentNoLabel->setText(student.studentNo());
    ui->nameEdit->setText(student.name());
    ui->classEdit->setText(student.className());
    ui->majorEdit->setText(student.major());
}

Student StudentProfileDialog::getStudent() const
{
    Student student = m_student;
    student.setName(ui->nameEdit->text().trimmed());
    student.setClassName(ui->classEdit->text().trimmed());
    student.setMajor(ui->majorEdit->text().trimmed());
    return student;
}
