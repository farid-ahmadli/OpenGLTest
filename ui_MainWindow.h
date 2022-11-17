/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Wed 20. Jan 17:38:31 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "GraphWindow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Plot_as_Image;
    QAction *actionSave_Plot_to_SVG;
    QAction *actionExit;
    QAction *actionSave_Plot_Image;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GraphWindow *widget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        actionSave_Plot_as_Image = new QAction(MainWindow);
        actionSave_Plot_as_Image->setObjectName(QString::fromUtf8("actionSave_Plot_as_Image"));
        actionSave_Plot_to_SVG = new QAction(MainWindow);
        actionSave_Plot_to_SVG->setObjectName(QString::fromUtf8("actionSave_Plot_to_SVG"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSave_Plot_Image = new QAction(MainWindow);
        actionSave_Plot_Image->setObjectName(QString::fromUtf8("actionSave_Plot_Image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setMargin(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new GraphWindow(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionSave_Plot_Image);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave_Plot_as_Image->setText(QApplication::translate("MainWindow", "Save Plot as Image...", 0, QApplication::UnicodeUTF8));
        actionSave_Plot_to_SVG->setText(QApplication::translate("MainWindow", "Save Plot to SVG", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionSave_Plot_Image->setText(QApplication::translate("MainWindow", "Save Plot Image", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
