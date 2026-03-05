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
    ui->descriptionEdit->setPlainText(course.description());
    
    for (int i = 0; i < ui->teacherComboBox->count(); ++i) {
        if (ui->teacherComboBox->itemData(i).toInt() == course.teacherId()) {
            ui->teacherComboBox->setCurrentIndex(i);
            break;
        }
    }
}

Course CourseDialog::getCourse() const
{
    Course course;
    course.setCourseNo(ui->courseNoEdit->text().trimmed());
    course.setCourseName(ui->courseNameEdit->text().trimmed());
    
    int teacherId = ui->teacherComboBox->currentData().toInt();
    course.setTeacherId(teacherId > 0 ? teacherId : 0);
    
    course.setCredit(ui->creditSpinBox->value());
    course.setHours(ui->hoursSpinBox->value());
    course.setDescription(ui->descriptionEdit->toPlainText().trimmed());
    return course;
}

void CourseDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑课程" : "添加课程");
}

void CourseDialog::setTeachers(const QVector<Teacher>& teachers)
{
    ui->teacherComboBox->clear();
    ui->teacherComboBox->addItem("未指定", 0);
    
    for (const Teacher& teacher : teachers) {
        ui->teacherComboBox->addItem(
            QString("%1 (%2)").arg(teacher.name(), teacher.teacherNo()),
            teacher.id()
        );
    }
}
