#include "teacherprofiledialog.h"
#include "ui_teacherprofiledialog.h"

TeacherProfileDialog::TeacherProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherProfileDialog)
{
    ui->setupUi(this);
    setWindowTitle("编辑个人信息");
}

TeacherProfileDialog::~TeacherProfileDialog()
{
    delete ui;
}

void TeacherProfileDialog::setTeacher(const Teacher& teacher)
{
    m_teacher = teacher;
    
    ui->teacherNoLabel->setText(teacher.teacherNo());
    ui->nameEdit->setText(teacher.name());
    ui->genderCombo->setCurrentText(teacher.gender());
    ui->ageSpinBox->setValue(teacher.age());
    ui->departmentEdit->setText(teacher.department());
    ui->titleEdit->setText(teacher.title());
    ui->phoneEdit->setText(teacher.phone());
    ui->emailEdit->setText(teacher.email());
}

Teacher TeacherProfileDialog::getTeacher() const
{
    Teacher teacher = m_teacher;
    teacher.setName(ui->nameEdit->text().trimmed());
    teacher.setGender(ui->genderCombo->currentText());
    teacher.setAge(ui->ageSpinBox->value());
    teacher.setDepartment(ui->departmentEdit->text().trimmed());
    teacher.setTitle(ui->titleEdit->text().trimmed());
    teacher.setPhone(ui->phoneEdit->text().trimmed());
    teacher.setEmail(ui->emailEdit->text().trimmed());
    return teacher;
}
