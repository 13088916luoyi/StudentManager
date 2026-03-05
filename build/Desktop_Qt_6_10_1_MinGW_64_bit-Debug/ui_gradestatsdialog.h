/********************************************************************************
** Form generated from reading UI file 'gradestatsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADESTATSDIALOG_H
#define UI_GRADESTATSDIALOG_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GradeStatsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *courseNameLabel;
    QGroupBox *statsGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_avg;
    QLabel *avgLabel;
    QLabel *label_max;
    QLabel *maxLabel;
    QLabel *label_min;
    QLabel *minLabel;
    QLabel *label_count;
    QLabel *countLabel;
    QLabel *label_pass;
    QLabel *passRateLabel;
    QLabel *label_excellent;
    QLabel *excellentRateLabel;
    QGroupBox *chartGroupBox;
    QVBoxLayout *verticalLayout_chart;
    QChartView *chartView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GradeStatsDialog)
    {
        if (GradeStatsDialog->objectName().isEmpty())
            GradeStatsDialog->setObjectName("GradeStatsDialog");
        GradeStatsDialog->resize(700, 550);
        verticalLayout = new QVBoxLayout(GradeStatsDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        courseNameLabel = new QLabel(GradeStatsDialog);
        courseNameLabel->setObjectName("courseNameLabel");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        courseNameLabel->setFont(font);
        courseNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(courseNameLabel);

        statsGroupBox = new QGroupBox(GradeStatsDialog);
        statsGroupBox->setObjectName("statsGroupBox");
        QFont font1;
        font1.setPointSize(11);
        statsGroupBox->setFont(font1);
        gridLayout = new QGridLayout(statsGroupBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(10);
        label_avg = new QLabel(statsGroupBox);
        label_avg->setObjectName("label_avg");
        label_avg->setFont(font1);

        gridLayout->addWidget(label_avg, 0, 0, 1, 1);

        avgLabel = new QLabel(statsGroupBox);
        avgLabel->setObjectName("avgLabel");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        avgLabel->setFont(font2);

        gridLayout->addWidget(avgLabel, 0, 1, 1, 1);

        label_max = new QLabel(statsGroupBox);
        label_max->setObjectName("label_max");
        label_max->setFont(font1);

        gridLayout->addWidget(label_max, 0, 2, 1, 1);

        maxLabel = new QLabel(statsGroupBox);
        maxLabel->setObjectName("maxLabel");
        maxLabel->setFont(font2);

        gridLayout->addWidget(maxLabel, 0, 3, 1, 1);

        label_min = new QLabel(statsGroupBox);
        label_min->setObjectName("label_min");
        label_min->setFont(font1);

        gridLayout->addWidget(label_min, 1, 0, 1, 1);

        minLabel = new QLabel(statsGroupBox);
        minLabel->setObjectName("minLabel");
        minLabel->setFont(font2);

        gridLayout->addWidget(minLabel, 1, 1, 1, 1);

        label_count = new QLabel(statsGroupBox);
        label_count->setObjectName("label_count");
        label_count->setFont(font1);

        gridLayout->addWidget(label_count, 1, 2, 1, 1);

        countLabel = new QLabel(statsGroupBox);
        countLabel->setObjectName("countLabel");
        countLabel->setFont(font2);

        gridLayout->addWidget(countLabel, 1, 3, 1, 1);

        label_pass = new QLabel(statsGroupBox);
        label_pass->setObjectName("label_pass");
        label_pass->setFont(font1);

        gridLayout->addWidget(label_pass, 2, 0, 1, 1);

        passRateLabel = new QLabel(statsGroupBox);
        passRateLabel->setObjectName("passRateLabel");
        passRateLabel->setFont(font2);

        gridLayout->addWidget(passRateLabel, 2, 1, 1, 1);

        label_excellent = new QLabel(statsGroupBox);
        label_excellent->setObjectName("label_excellent");
        label_excellent->setFont(font1);

        gridLayout->addWidget(label_excellent, 2, 2, 1, 1);

        excellentRateLabel = new QLabel(statsGroupBox);
        excellentRateLabel->setObjectName("excellentRateLabel");
        excellentRateLabel->setFont(font2);

        gridLayout->addWidget(excellentRateLabel, 2, 3, 1, 1);


        verticalLayout->addWidget(statsGroupBox);

        chartGroupBox = new QGroupBox(GradeStatsDialog);
        chartGroupBox->setObjectName("chartGroupBox");
        chartGroupBox->setFont(font1);
        verticalLayout_chart = new QVBoxLayout(chartGroupBox);
        verticalLayout_chart->setObjectName("verticalLayout_chart");
        verticalLayout_chart->setContentsMargins(10, 10, 10, 10);
        chartView = new QChartView(chartGroupBox);
        chartView->setObjectName("chartView");
        chartView->setMinimumSize(QSize(400, 250));

        verticalLayout_chart->addWidget(chartView);


        verticalLayout->addWidget(chartGroupBox);

        buttonBox = new QDialogButtonBox(GradeStatsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GradeStatsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, GradeStatsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(GradeStatsDialog);
    } // setupUi

    void retranslateUi(QDialog *GradeStatsDialog)
    {
        GradeStatsDialog->setWindowTitle(QCoreApplication::translate("GradeStatsDialog", "\346\210\220\347\273\251\347\273\237\350\256\241\345\210\206\346\236\220", nullptr));
        courseNameLabel->setText(QCoreApplication::translate("GradeStatsDialog", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        statsGroupBox->setTitle(QCoreApplication::translate("GradeStatsDialog", "\347\273\237\350\256\241\346\225\260\346\215\256", nullptr));
        label_avg->setText(QCoreApplication::translate("GradeStatsDialog", "\345\271\263\345\235\207\345\210\206\357\274\232", nullptr));
        avgLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        label_max->setText(QCoreApplication::translate("GradeStatsDialog", "\346\234\200\351\253\230\345\210\206\357\274\232", nullptr));
        maxLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        label_min->setText(QCoreApplication::translate("GradeStatsDialog", "\346\234\200\344\275\216\345\210\206\357\274\232", nullptr));
        minLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        label_count->setText(QCoreApplication::translate("GradeStatsDialog", "\345\255\246\347\224\237\346\225\260\357\274\232", nullptr));
        countLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        label_pass->setText(QCoreApplication::translate("GradeStatsDialog", "\345\217\212\346\240\274\347\216\207\357\274\232", nullptr));
        passRateLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        label_excellent->setText(QCoreApplication::translate("GradeStatsDialog", "\344\274\230\347\247\200\347\216\207\357\274\232", nullptr));
        excellentRateLabel->setText(QCoreApplication::translate("GradeStatsDialog", "-", nullptr));
        chartGroupBox->setTitle(QCoreApplication::translate("GradeStatsDialog", "\346\210\220\347\273\251\345\210\206\345\270\203\345\233\276\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GradeStatsDialog: public Ui_GradeStatsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADESTATSDIALOG_H
