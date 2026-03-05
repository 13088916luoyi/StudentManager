/********************************************************************************
** Form generated from reading UI file 'courseselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESELECTIONDIALOG_H
#define UI_COURSESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *selectAllButton;
    QPushButton *deselectAllButton;
    QSpacerItem *horizontalSpacer;
    QLabel *selectedCountLabel;
    QTableWidget *courseTable;
    QLabel *hintLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CourseSelectionDialog)
    {
        if (CourseSelectionDialog->objectName().isEmpty())
            CourseSelectionDialog->setObjectName("CourseSelectionDialog");
        CourseSelectionDialog->resize(600, 450);
        CourseSelectionDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"QLabel {\n"
"    font-size: 13px;\n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"}\n"
"QTableWidget {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 12px;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #4a90d9;\n"
"    color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #4a90d9;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"QPushButton {\n"
"    padding: 10px 20px;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"    min-width: 80px;\n"
"}\n"
"QPushButton[text=\"\347\241\256\345\256\232\"], QPushButton[text=\"OK\"] {\n"
"    background-color: #4a90d9;\n"
"    color: white;\n"
"}\n"
"QPushButton[text=\"\347\241\256\345\256\232\"]:hover, QPushButton[text=\"OK\"]:hover {\n"
"    ba"
                        "ckground-color: #3a7bc8;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"], QPushButton[text=\"Cancel\"] {\n"
"    background-color: #e0e0e0;\n"
"    color: #333333;\n"
"}\n"
"QPushButton[text=\"\345\217\226\346\266\210\"]:hover, QPushButton[text=\"Cancel\"]:hover {\n"
"    background-color: #d0d0d0;\n"
"}\n"
"QPushButton#selectAllButton, QPushButton#deselectAllButton {\n"
"    background-color: #5bc0de;\n"
"    color: white;\n"
"    padding: 6px 12px;\n"
"    font-size: 11px;\n"
"    min-width: 60px;\n"
"}\n"
"QPushButton#selectAllButton:hover, QPushButton#deselectAllButton:hover {\n"
"    background-color: #46b8da;\n"
"}"));
        verticalLayout = new QVBoxLayout(CourseSelectionDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        titleLabel = new QLabel(CourseSelectionDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #4a90d9;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        selectAllButton = new QPushButton(CourseSelectionDialog);
        selectAllButton->setObjectName("selectAllButton");

        buttonLayout->addWidget(selectAllButton);

        deselectAllButton = new QPushButton(CourseSelectionDialog);
        deselectAllButton->setObjectName("deselectAllButton");

        buttonLayout->addWidget(deselectAllButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        selectedCountLabel = new QLabel(CourseSelectionDialog);
        selectedCountLabel->setObjectName("selectedCountLabel");
        selectedCountLabel->setStyleSheet(QString::fromUtf8("color: #666666; font-weight: normal;"));

        buttonLayout->addWidget(selectedCountLabel);


        verticalLayout->addLayout(buttonLayout);

        courseTable = new QTableWidget(CourseSelectionDialog);
        courseTable->setObjectName("courseTable");
        courseTable->setMinimumSize(QSize(0, 280));
        courseTable->setSelectionMode(QAbstractItemView::MultiSelection);
        courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(courseTable);

        hintLabel = new QLabel(CourseSelectionDialog);
        hintLabel->setObjectName("hintLabel");
        hintLabel->setStyleSheet(QString::fromUtf8("color: #999999; font-size: 11px; font-weight: normal;"));
        hintLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(hintLabel);

        buttonBox = new QDialogButtonBox(CourseSelectionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CourseSelectionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CourseSelectionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CourseSelectionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CourseSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CourseSelectionDialog)
    {
        CourseSelectionDialog->setWindowTitle(QCoreApplication::translate("CourseSelectionDialog", "\351\200\211\346\213\251\346\225\231\346\216\210\350\257\276\347\250\213", nullptr));
        titleLabel->setText(QCoreApplication::translate("CourseSelectionDialog", "\351\200\211\346\213\251\346\225\231\346\216\210\350\257\276\347\250\213", nullptr));
        selectAllButton->setText(QCoreApplication::translate("CourseSelectionDialog", "\345\205\250\351\200\211", nullptr));
        deselectAllButton->setText(QCoreApplication::translate("CourseSelectionDialog", "\345\205\250\344\270\215\351\200\211", nullptr));
        selectedCountLabel->setText(QCoreApplication::translate("CourseSelectionDialog", "\345\267\262\351\200\211\346\213\251 0 \351\227\250\350\257\276\347\250\213", nullptr));
        hintLabel->setText(QCoreApplication::translate("CourseSelectionDialog", "\346\217\220\347\244\272\357\274\232\347\202\271\345\207\273\350\241\214\345\217\257\351\200\211\344\270\255/\345\217\226\346\266\210\351\200\211\344\270\255\350\257\276\347\250\213\357\274\214\346\224\257\346\214\201\345\244\232\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseSelectionDialog: public Ui_CourseSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESELECTIONDIALOG_H
