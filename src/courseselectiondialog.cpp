#include "courseselectiondialog.h"
#include "ui_courseselectiondialog.h"
#include <QHeaderView>

CourseSelectionDialog::CourseSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseSelectionDialog)
{
    ui->setupUi(this);
    setWindowTitle("选课");
    
    ui->courseTable->setColumnCount(4);
    ui->courseTable->setHorizontalHeaderLabels({"课程号", "课程名", "学分", "学时"});
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->courseTable->setStyleSheet("QTableWidget::item:selected { background-color: #4a90d9; color: white; }");
    ui->courseTable->verticalHeader()->setDefaultSectionSize(35);
    
    QFont tableFont;
    tableFont.setPointSize(11);
    ui->courseTable->setFont(tableFont);
}

CourseSelectionDialog::~CourseSelectionDialog()
{
    delete ui;
}

void CourseSelectionDialog::setAvailableCourses(const QVector<Course>& courses)
{
    m_courses = courses;
    
    ui->courseTable->setRowCount(courses.size());
    
    for (int i = 0; i < courses.size(); ++i) {
        const Course& c = courses[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(c.courseNo());
        item0->setData(Qt::UserRole, c.id());
        ui->courseTable->setItem(i, 0, item0);
        ui->courseTable->setItem(i, 1, new QTableWidgetItem(c.courseName()));
        ui->courseTable->setItem(i, 2, new QTableWidgetItem(QString::number(c.credit())));
        ui->courseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.hours())));
    }
}

int CourseSelectionDialog::getSelectedCourseId() const
{
    int row = ui->courseTable->currentRow();
    if (row < 0) return -1;
    
    return ui->courseTable->item(row, 0)->data(Qt::UserRole).toInt();
}
