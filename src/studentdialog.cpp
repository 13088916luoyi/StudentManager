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
    
    int genderIndex = (student.gender() == "女") ? 1 : 0;
    ui->genderComboBox->setCurrentIndex(genderIndex);
    
    ui->ageSpinBox->setValue(student.age());
    
    int deptIndex = ui->departmentComboBox->findText(student.department());
    if (deptIndex >= 0) {
        ui->departmentComboBox->setCurrentIndex(deptIndex);
    } else {
        ui->departmentComboBox->setEditText(student.department());
    }
    
    int classIndex = ui->classComboBox->findText(student.className());
    if (classIndex >= 0) {
        ui->classComboBox->setCurrentIndex(classIndex);
    } else {
        ui->classComboBox->setEditText(student.className());
    }
    
    ui->phoneEdit->setText(student.phone());
    ui->emailEdit->setText(student.email());
}

Student StudentDialog::getStudent() const
{
    Student student;
    student.setStudentNo(ui->studentNoEdit->text().trimmed());
    student.setName(ui->nameEdit->text().trimmed());
    student.setGender(ui->genderComboBox->currentText());
    student.setAge(ui->ageSpinBox->value());
    student.setDepartment(ui->departmentComboBox->currentText());
    student.setClassName(ui->classComboBox->currentText());
    student.setPhone(ui->phoneEdit->text().trimmed());
    student.setEmail(ui->emailEdit->text().trimmed());
    return student;
}

void StudentDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑学生" : "添加学生");
}
