/********************************************************************************
** Form generated from reading ui file 'qtview.ui'
**
** Created: Thu Jul 8 21:17:10 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QTVIEW_H
#define UI_QTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QtViewClass
{
public:

    void setupUi(QDialog *QtViewClass)
    {
        if (QtViewClass->objectName().isEmpty())
            QtViewClass->setObjectName(QString::fromUtf8("QtViewClass"));
        QtViewClass->resize(400, 300);

        retranslateUi(QtViewClass);

        QMetaObject::connectSlotsByName(QtViewClass);
    } // setupUi

    void retranslateUi(QDialog *QtViewClass)
    {
        QtViewClass->setWindowTitle(QApplication::translate("QtViewClass", "QtView", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QtViewClass);
    } // retranslateUi

};

namespace Ui {
    class QtViewClass: public Ui_QtViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTVIEW_H
