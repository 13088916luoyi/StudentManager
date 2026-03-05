#ifndef GRADESTATSDIALOG_H
#define GRADESTATSDIALOG_H

#include <QDialog>
#include <QChartView>
#include <QChart>

namespace Ui {
class GradeStatsDialog;
}

class GradeStatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradeStatsDialog(QWidget *parent = nullptr);
    ~GradeStatsDialog();

    void setCourseName(const QString& name);
    void setGrades(const QVector<int>& grades);

private:
    Ui::GradeStatsDialog *ui;
    QChart* m_chart;
    
    void updateStats(const QVector<int>& grades);
    void updateChart(const QVector<int>& grades);
};

#endif // GRADESTATSDIALOG_H
