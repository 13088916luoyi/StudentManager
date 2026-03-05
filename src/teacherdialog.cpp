#include "teacherdialog.h"
#include "ui_teacherdialog.h"
#include "courseselectiondialog.h"
#include <QMessageBox>

TeacherDialog::TeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherDialog)
{
    ui->setupUi(this);
    setWindowTitle("教师信息");
    
    // 连接选择课程按钮
    connect(ui->selectCoursesButton, &QPushButton::clicked, this, &TeacherDialog::onSelectCoursesClicked);
}

TeacherDialog::~TeacherDialog()
{
    delete ui;
}

void TeacherDialog::setTeacher(const Teacher& teacher)
{
    ui->teacherNoEdit->setText(teacher.teacherNo());
    ui->nameEdit->setText(teacher.name());
    
    // 获取教师当前的课程ID
    m_selectedCourseIds.clear();
    for (const QString& courseName : teacher.courses()) {
        for (const Course& c : m_availableCourses) {
            if (c.courseName() == courseName) {
                m_selectedCourseIds.append(c.id());
                break;
            }
        }
    }
    
    updateCoursesDisplay();
}

Teacher TeacherDialog::getTeacher() const
{
    Teacher teacher;
    teacher.setTeacherNo(ui->teacherNoEdit->text().trimmed());
    teacher.setName(ui->nameEdit->text().trimmed());
    
    // 获取选中的课程名称
    QStringList selectedCourses;
    for (int courseId : m_selectedCourseIds) {
        for (const Course& c : m_availableCourses) {
            if (c.id() == courseId) {
                selectedCourses.append(c.courseName());
                break;
            }
        }
    }
    teacher.setCourses(selectedCourses);
    
    return teacher;
}

void TeacherDialog::setEditMode(bool edit)
{
    m_editMode = edit;
    setWindowTitle(edit ? "编辑教师" : "添加教师");
    ui->teacherNoEdit->setEnabled(!edit);
}

void TeacherDialog::setAvailableCourses(const QVector<Course>& courses)
{
    m_availableCourses = courses;
}

QVector<int> TeacherDialog::getSelectedCourseIds() const
{
    return m_selectedCourseIds;
}

void TeacherDialog::onSelectCoursesClicked()
{
    if (m_availableCourses.isEmpty()) {
        QMessageBox::warning(this, "提示", "没有可选的课程");
        return;
    }
    
    CourseSelectionDialog dialog(this);
    dialog.setCourses(m_availableCourses);
    dialog.setSelectedCourseIds(m_selectedCourseIds);
    
    if (dialog.exec() == QDialog::Accepted) {
        m_selectedCourseIds = dialog.getSelectedCourseIds();
        updateCoursesDisplay();
    }
}

void TeacherDialog::updateCoursesDisplay()
{
    if (m_selectedCourseIds.isEmpty()) {
        ui->coursesDisplayLabel->setText("未选择课程");
        return;
    }
    
    QStringList courseNames;
    for (int courseId : m_selectedCourseIds) {
        for (const Course& c : m_availableCourses) {
            if (c.id() == courseId) {
                courseNames.append(c.courseName());
                break;
            }
        }
    }
    
    ui->coursesDisplayLabel->setText(courseNames.join(", "));
}
