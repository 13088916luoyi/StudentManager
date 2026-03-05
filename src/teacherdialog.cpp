#include "teacherdialog.h"
#include "ui_teacherdialog.h"

TeacherDialog::TeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherDialog)
{
    ui->setupUi(this);
    setWindowTitle("教师信息");
}

TeacherDialog::~TeacherDialog()
{
    delete ui;
}

void TeacherDialog::setTeacher(const Teacher& teacher)
{
    ui->teacherNoEdit->setText(teacher.teacherNo());
    ui->nameEdit->setText(teacher.name());
    
    int genderIndex = (teacher.gender() == "女") ? 1 : 0;
    ui->genderComboBox->setCurrentIndex(genderIndex);
    
    ui->ageSpinBox->setValue(teacher.age());
    
    int deptIndex = ui->departmentComboBox->findText(teacher.department());
    if (deptIndex >= 0) {
        ui->departmentComboBox->setCurrentIndex(deptIndex);
    } else {
        ui->departmentComboBox->setEditText(teacher.department());
    }
    
    int titleIndex = ui->titleComboBox->findText(teacher.title());
    if (titleIndex >= 0) {
        ui->titleComboBox->setCurrentIndex(titleIndex);
    } else {
        ui->titleComboBox->setEditText(teacher.title());
    }
    
    ui->phoneEdit->setText(teacher.phone());
    ui->emailEdit->setText(teacher.email());
}

Teacher TeacherDialog::getTeacher() const
{
    Teacher teacher;
    teacher.setTeacherNo(ui->teacherNoEdit->text().trimmed());
    teacher.setName(ui->nameEdit->text().trimmed());
    teacher.setGender(ui->genderComboBox->currentText());
    teacher.setAge(ui->ageSpinBox->value());
    teacher.setDepartment(ui->departmentComboBox->currentText());
    teacher.setTitle(ui->titleComboBox->currentText());
    teacher.setPhone(ui->phoneEdit->text().trimmed());
    teacher.setEmail(ui->emailEdit->text().trimmed());
    return teacher;
}

void TeacherDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑教师" : "添加教师");
}
