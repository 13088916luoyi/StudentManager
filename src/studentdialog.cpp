#include "studentdialog.h"
#include "ui_studentdialog.h"

StudentDialog::StudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    setWindowTitle("学生信息");
}

StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::setStudent(const Student& student)
{
    ui->studentNoEdit->setText(student.studentNo());
    ui->nameEdit->setText(student.name());
    ui->classEdit->setText(student.className());
    ui->departmentEdit->setText(student.major());
}

Student StudentDialog::getStudent() const
{
    Student student;
    student.setStudentNo(ui->studentNoEdit->text().trimmed());
    student.setName(ui->nameEdit->text().trimmed());
    student.setClassName(ui->classEdit->text().trimmed());
    student.setMajor(ui->departmentEdit->text().trimmed());
    return student;
}

void StudentDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑学生" : "添加学生");
    ui->studentNoEdit->setEnabled(!edit);
}
