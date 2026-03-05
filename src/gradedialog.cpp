#include "gradedialog.h"
#include "ui_gradedialog.h"

GradeDialog::GradeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradeDialog)
{
    ui->setupUi(this);
    setWindowTitle("成绩信息");
}

GradeDialog::~GradeDialog()
{
    delete ui;
}

void GradeDialog::setGrade(const Grade& grade)
{
    ui->gradeSpinBox->setValue(grade.grade());
    
    for (int i = 0; i < ui->studentComboBox->count(); ++i) {
        if (ui->studentComboBox->itemData(i).toInt() == grade.studentId()) {
            ui->studentComboBox->setCurrentIndex(i);
            break;
        }
    }
    
    for (int i = 0; i < ui->courseComboBox->count(); ++i) {
        if (ui->courseComboBox->itemData(i).toInt() == grade.courseId()) {
            ui->courseComboBox->setCurrentIndex(i);
            break;
        }
    }
}

Grade GradeDialog::getGrade() const
{
    Grade grade;
    grade.setStudentId(ui->studentComboBox->currentData().toInt());
    grade.setCourseId(ui->courseComboBox->currentData().toInt());
    grade.setGrade(ui->gradeSpinBox->value());
    return grade;
}

void GradeDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑成绩" : "添加成绩");
}

void GradeDialog::setStudents(const QVector<Student>& students)
{
    ui->studentComboBox->clear();
    for (const Student& student : students) {
        ui->studentComboBox->addItem(
            QString("%1 (%2)").arg(student.name(), student.studentNo()),
            student.id()
        );
    }
}

void GradeDialog::setCourses(const QVector<Course>& courses)
{
    ui->courseComboBox->clear();
    for (const Course& course : courses) {
        ui->courseComboBox->addItem(
            QString("%1 (%2)").arg(course.courseName(), course.courseNo()),
            course.id()
        );
    }
}
