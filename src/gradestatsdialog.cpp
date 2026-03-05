#include "gradestatsdialog.h"
#include "ui_gradestatsdialog.h"
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPainter>
#include <cmath>

GradeStatsDialog::GradeStatsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradeStatsDialog),
    m_chart(new QChart())
{
    ui->setupUi(this);
    setWindowTitle("成绩统计分析");
    
    m_chart->setAnimationOptions(QChart::SeriesAnimations);
    m_chart->legend()->setVisible(true);
    m_chart->legend()->setAlignment(Qt::AlignBottom);
    
    ui->chartView->setChart(m_chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}

GradeStatsDialog::~GradeStatsDialog()
{
    delete ui;
}

void GradeStatsDialog::setCourseName(const QString& name)
{
    ui->courseNameLabel->setText(QString("课程：%1 成绩统计").arg(name));
}

void GradeStatsDialog::setGrades(const QVector<int>& grades)
{
    updateStats(grades);
    updateChart(grades);
}

void GradeStatsDialog::updateStats(const QVector<int>& grades)
{
    if (grades.isEmpty()) {
        ui->avgLabel->setText("-");
        ui->maxLabel->setText("-");
        ui->minLabel->setText("-");
        ui->countLabel->setText("0");
        ui->passRateLabel->setText("-");
        ui->excellentRateLabel->setText("-");
        return;
    }
    
    double sum = 0;
    int maxGrade = 0;
    int minGrade = 100;
    int passCount = 0;
    int excellentCount = 0;
    
    for (int g : grades) {
        sum += g;
        if (g > maxGrade) maxGrade = g;
        if (g < minGrade) minGrade = g;
        if (g >= 60) passCount++;
        if (g >= 90) excellentCount++;
    }
    
    double avg = sum / grades.size();
    double passRate = (double)passCount / grades.size() * 100;
    double excellentRate = (double)excellentCount / grades.size() * 100;
    
    ui->avgLabel->setText(QString::number(avg, 'f', 1));
    ui->maxLabel->setText(QString::number(maxGrade));
    ui->minLabel->setText(QString::number(minGrade));
    ui->countLabel->setText(QString::number(grades.size()));
    ui->passRateLabel->setText(QString("%1%").arg(QString::number(passRate, 'f', 1)));
    ui->excellentRateLabel->setText(QString("%1%").arg(QString::number(excellentRate, 'f', 1)));
}

void GradeStatsDialog::updateChart(const QVector<int>& grades)
{
    m_chart->removeAllSeries();
    
    for (QAbstractAxis* axis : m_chart->axes()) {
        m_chart->removeAxis(axis);
    }
    
    if (grades.isEmpty()) {
        m_chart->setTitle("暂无成绩数据");
        return;
    }
    
    int range0_59 = 0;
    int range60_69 = 0;
    int range70_79 = 0;
    int range80_89 = 0;
    int range90_100 = 0;
    
    for (int g : grades) {
        if (g < 60) range0_59++;
        else if (g < 70) range60_69++;
        else if (g < 80) range70_79++;
        else if (g < 90) range80_89++;
        else range90_100++;
    }
    
    QBarSet* set0 = new QBarSet("0-59分");
    *set0 << range0_59;
    set0->setColor(QColor(231, 76, 60));
    
    QBarSet* set1 = new QBarSet("60-69分");
    *set1 << range60_69;
    set1->setColor(QColor(241, 196, 15));
    
    QBarSet* set2 = new QBarSet("70-79分");
    *set2 << range70_79;
    set2->setColor(QColor(46, 204, 113));
    
    QBarSet* set3 = new QBarSet("80-89分");
    *set3 << range80_89;
    set3->setColor(QColor(52, 152, 219));
    
    QBarSet* set4 = new QBarSet("90-100分");
    *set4 << range90_100;
    set4->setColor(QColor(155, 89, 182));
    
    QBarSeries* series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->setBarWidth(0.8);
    
    m_chart->addSeries(series);
    m_chart->setTitle("成绩分布柱状图");
    
    QStringList categories;
    categories << "分数段";
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    
    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("人数");
    axisY->setRange(0, std::max({range0_59, range60_69, range70_79, range80_89, range90_100}) + 1);
    axisY->setTickCount(std::max({range0_59, range60_69, range70_79, range80_89, range90_100}) + 2);
    m_chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}
