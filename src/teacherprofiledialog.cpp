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
}

Teacher TeacherProfileDialog::getTeacher() const
{
    Teacher teacher = m_teacher;
    teacher.setName(ui->nameEdit->text().trimmed());
    return teacher;
}
