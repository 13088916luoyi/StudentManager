#include "courseselectiondialog.h"
#include "ui_courseselectiondialog.h"
#include <QHeaderView>

CourseSelectionDialog::CourseSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseSelectionDialog)
{
    ui->setupUi(this);
    setWindowTitle("选择教授课程");

    // 设置表格列
    ui->courseTable->setColumnCount(5);
    ui->courseTable->setHorizontalHeaderLabels({"课程号", "课程名", "学分", "学时", "课程类别"});
    ui->courseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->courseTable->verticalHeader()->setDefaultSectionSize(30);
    ui->courseTable->verticalHeader()->setFixedWidth(50);
    ui->courseTable->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 连接信号
    connect(ui->selectAllButton, &QPushButton::clicked, this, &CourseSelectionDialog::onSelectAllClicked);
    connect(ui->deselectAllButton, &QPushButton::clicked, this, &CourseSelectionDialog::onDeselectAllClicked);
    connect(ui->courseTable->selectionModel(), &QItemSelectionModel::selectionChanged, this, &CourseSelectionDialog::onSelectionChanged);
}

CourseSelectionDialog::~CourseSelectionDialog()
{
    delete ui;
}

void CourseSelectionDialog::setCourses(const QVector<Course>& courses)
{
    m_courses = courses;
    ui->courseTable->setRowCount(courses.size());

    for (int i = 0; i < courses.size(); ++i) {
        const Course& c = courses[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(c.courseNo());
        item0->setData(Qt::UserRole, c.id());  // 存储课程ID
        ui->courseTable->setItem(i, 0, item0);
        ui->courseTable->setItem(i, 1, new QTableWidgetItem(c.courseName()));
        ui->courseTable->setItem(i, 2, new QTableWidgetItem(QString::number(c.credit())));
        ui->courseTable->setItem(i, 3, new QTableWidgetItem(QString::number(c.hours())));
        ui->courseTable->setItem(i, 4, new QTableWidgetItem(c.courseType()));
    }

    updateSelectedCount();
}

void CourseSelectionDialog::setSelectedCourseIds(const QVector<int>& courseIds)
{
    // 清除当前选择
    ui->courseTable->clearSelection();

    // 选中指定的课程
    for (int i = 0; i < ui->courseTable->rowCount(); ++i) {
        int courseId = ui->courseTable->item(i, 0)->data(Qt::UserRole).toInt();
        if (courseIds.contains(courseId)) {
            ui->courseTable->selectRow(i);
        }
    }

    updateSelectedCount();
}

QVector<int> CourseSelectionDialog::getSelectedCourseIds() const
{
    QVector<int> selectedIds;
    for (int i = 0; i < ui->courseTable->rowCount(); ++i) {
        if (ui->courseTable->selectionModel()->isRowSelected(i, QModelIndex())) {
            int courseId = ui->courseTable->item(i, 0)->data(Qt::UserRole).toInt();
            selectedIds.append(courseId);
        }
    }
    return selectedIds;
}

void CourseSelectionDialog::onSelectAllClicked()
{
    ui->courseTable->selectAll();
    updateSelectedCount();
}

void CourseSelectionDialog::onDeselectAllClicked()
{
    ui->courseTable->clearSelection();
    updateSelectedCount();
}

void CourseSelectionDialog::onSelectionChanged()
{
    updateSelectedCount();
}

void CourseSelectionDialog::updateSelectedCount()
{
    int count = 0;
    for (int i = 0; i < ui->courseTable->rowCount(); ++i) {
        if (ui->courseTable->selectionModel()->isRowSelected(i, QModelIndex())) {
            count++;
        }
    }
    ui->selectedCountLabel->setText(QString("已选择 %1 门课程").arg(count));
}
