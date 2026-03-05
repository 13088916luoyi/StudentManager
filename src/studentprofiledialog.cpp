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
    ui->genderCombo->setCurrentText(student.gender());
    ui->ageSpinBox->setValue(student.age());
    ui->departmentEdit->setText(student.department());
    ui->classEdit->setText(student.className());
    ui->phoneEdit->setText(student.phone());
    ui->emailEdit->setText(student.email());
}

Student StudentProfileDialog::getStudent() const
{
    Student student = m_student;
    student.setName(ui->nameEdit->text().trimmed());
    student.setGender(ui->genderCombo->currentText());
    student.setAge(ui->ageSpinBox->value());
    student.setDepartment(ui->departmentEdit->text().trimmed());
    student.setClassName(ui->classEdit->text().trimmed());
    student.setPhone(ui->phoneEdit->text().trimmed());
    student.setEmail(ui->emailEdit->text().trimmed());
    return student;
}
