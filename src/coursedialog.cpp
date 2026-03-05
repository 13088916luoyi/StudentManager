#include "coursedialog.h"
#include "ui_coursedialog.h"

CourseDialog::CourseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseDialog)
{
    ui->setupUi(this);
    setWindowTitle("课程信息");
}

CourseDialog::~CourseDialog()
{
    delete ui;
}

void CourseDialog::setCourse(const Course& course)
{
    ui->courseNoEdit->setText(course.courseNo());
    ui->courseNameEdit->setText(course.courseName());
    ui->creditSpinBox->setValue(course.credit());
    ui->hoursSpinBox->setValue(course.hours());
    
    int typeIndex = ui->courseTypeComboBox->findText(course.courseType());
    if (typeIndex >= 0) {
        ui->courseTypeComboBox->setCurrentIndex(typeIndex);
    }
}

Course CourseDialog::getCourse() const
{
    Course course;
    course.setCourseNo(ui->courseNoEdit->text().trimmed());
    course.setCourseName(ui->courseNameEdit->text().trimmed());
    course.setCredit(ui->creditSpinBox->value());
    course.setHours(ui->hoursSpinBox->value());
    course.setCourseType(ui->courseTypeComboBox->currentText());
    return course;
}

void CourseDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑课程" : "添加课程");
    ui->courseNoEdit->setEnabled(!edit);
}
