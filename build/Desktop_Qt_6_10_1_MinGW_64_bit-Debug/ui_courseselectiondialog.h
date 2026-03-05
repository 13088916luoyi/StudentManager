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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *courseTable;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CourseSelectionDialog)
    {
        if (CourseSelectionDialog->objectName().isEmpty())
            CourseSelectionDialog->setObjectName("CourseSelectionDialog");
        CourseSelectionDialog->resize(500, 400);
        verticalLayout = new QVBoxLayout(CourseSelectionDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        label = new QLabel(CourseSelectionDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        courseTable = new QTableWidget(CourseSelectionDialog);
        courseTable->setObjectName("courseTable");
        QFont font1;
        font1.setPointSize(11);
        courseTable->setFont(font1);
        courseTable->setSelectionMode(QAbstractItemView::SingleSelection);
        courseTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        courseTable->setAlternatingRowColors(true);

        verticalLayout->addWidget(courseTable);

        buttonBox = new QDialogButtonBox(CourseSelectionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CourseSelectionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CourseSelectionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CourseSelectionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CourseSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CourseSelectionDialog)
    {
        CourseSelectionDialog->setWindowTitle(QCoreApplication::translate("CourseSelectionDialog", "\351\200\211\350\257\276", nullptr));
        label->setText(QCoreApplication::translate("CourseSelectionDialog", "\345\217\257\351\200\211\350\257\276\347\250\213\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseSelectionDialog: public Ui_CourseSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESELECTIONDIALOG_H
