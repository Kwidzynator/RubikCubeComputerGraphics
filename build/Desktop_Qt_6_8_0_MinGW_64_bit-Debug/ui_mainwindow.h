/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *translationSliderLR;
    QSlider *translationUD;
    QSlider *rotationSlider;
    QSlider *scalingSliderLR;
    QSlider *scalingSliderUD;
    QSlider *shearingSliderOX;
    QSlider *shearingSliderOY;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(867, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        translationSliderLR = new QSlider(centralwidget);
        translationSliderLR->setObjectName("translationSliderLR");
        translationSliderLR->setGeometry(QRect(680, 50, 160, 22));
        translationSliderLR->setOrientation(Qt::Orientation::Horizontal);
        translationUD = new QSlider(centralwidget);
        translationUD->setObjectName("translationUD");
        translationUD->setGeometry(QRect(680, 80, 160, 22));
        translationUD->setOrientation(Qt::Orientation::Horizontal);
        rotationSlider = new QSlider(centralwidget);
        rotationSlider->setObjectName("rotationSlider");
        rotationSlider->setGeometry(QRect(680, 160, 160, 22));
        rotationSlider->setOrientation(Qt::Orientation::Horizontal);
        scalingSliderLR = new QSlider(centralwidget);
        scalingSliderLR->setObjectName("scalingSliderLR");
        scalingSliderLR->setGeometry(QRect(680, 220, 160, 22));
        scalingSliderLR->setOrientation(Qt::Orientation::Horizontal);
        scalingSliderUD = new QSlider(centralwidget);
        scalingSliderUD->setObjectName("scalingSliderUD");
        scalingSliderUD->setGeometry(QRect(680, 250, 160, 22));
        scalingSliderUD->setOrientation(Qt::Orientation::Horizontal);
        shearingSliderOX = new QSlider(centralwidget);
        shearingSliderOX->setObjectName("shearingSliderOX");
        shearingSliderOX->setGeometry(QRect(680, 300, 160, 22));
        shearingSliderOX->setOrientation(Qt::Orientation::Horizontal);
        shearingSliderOY = new QSlider(centralwidget);
        shearingSliderOY->setObjectName("shearingSliderOY");
        shearingSliderOY->setGeometry(QRect(680, 330, 160, 22));
        shearingSliderOY->setOrientation(Qt::Orientation::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(680, 480, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 30, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 140, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(680, 200, 49, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(680, 280, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 867, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "translation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "rotation", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "scaling", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "shearing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
