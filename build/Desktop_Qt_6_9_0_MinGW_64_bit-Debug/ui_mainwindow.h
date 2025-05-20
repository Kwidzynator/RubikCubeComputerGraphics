/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *translationSliderOX;
    QSlider *translationSliderOY;
    QSlider *rotationSliderOX;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QSlider *translationSliderOZ;
    QSlider *rotationSliderOY;
    QSlider *rotationSliderOZ;
    QToolButton *buttonTopRight;
    QToolButton *buttonTopLeft;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *buttonBottomLeft;
    QToolButton *toolButton_8;
    QToolButton *buttonBottomRight;
    QToolButton *buttonLeftUp;
    QToolButton *toolButton_11;
    QToolButton *buttonRightUp;
    QToolButton *toolButton_13;
    QToolButton *toolButton_14;
    QToolButton *toolButton_15;
    QToolButton *buttonLeftDown;
    QToolButton *toolButton_17;
    QToolButton *buttonRightDown;
    QToolButton *toolButton_16;
    QToolButton *buttonRightDown_2;
    QToolButton *buttonRightUp_2;
    QToolButton *toolButton_18;
    QToolButton *toolButton_19;
    QToolButton *toolButton_20;
    QToolButton *buttonLeftUp_2;
    QToolButton *toolButton_12;
    QToolButton *buttonLeftDown_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(867, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        translationSliderOX = new QSlider(centralwidget);
        translationSliderOX->setObjectName("translationSliderOX");
        translationSliderOX->setGeometry(QRect(680, 30, 160, 22));
        translationSliderOX->setOrientation(Qt::Orientation::Horizontal);
        translationSliderOY = new QSlider(centralwidget);
        translationSliderOY->setObjectName("translationSliderOY");
        translationSliderOY->setGeometry(QRect(680, 60, 160, 22));
        translationSliderOY->setOrientation(Qt::Orientation::Horizontal);
        rotationSliderOX = new QSlider(centralwidget);
        rotationSliderOX->setObjectName("rotationSliderOX");
        rotationSliderOX->setGeometry(QRect(680, 140, 160, 22));
        rotationSliderOX->setOrientation(Qt::Orientation::Horizontal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 520, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(680, 10, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 120, 71, 16));
        translationSliderOZ = new QSlider(centralwidget);
        translationSliderOZ->setObjectName("translationSliderOZ");
        translationSliderOZ->setGeometry(QRect(680, 90, 160, 22));
        translationSliderOZ->setOrientation(Qt::Orientation::Horizontal);
        rotationSliderOY = new QSlider(centralwidget);
        rotationSliderOY->setObjectName("rotationSliderOY");
        rotationSliderOY->setGeometry(QRect(680, 170, 160, 22));
        rotationSliderOY->setOrientation(Qt::Orientation::Horizontal);
        rotationSliderOZ = new QSlider(centralwidget);
        rotationSliderOZ->setObjectName("rotationSliderOZ");
        rotationSliderOZ->setGeometry(QRect(680, 200, 160, 22));
        rotationSliderOZ->setOrientation(Qt::Orientation::Horizontal);
        buttonTopRight = new QToolButton(centralwidget);
        buttonTopRight->setObjectName("buttonTopRight");
        buttonTopRight->setGeometry(QRect(810, 220, 31, 31));
        buttonTopLeft = new QToolButton(centralwidget);
        buttonTopLeft->setObjectName("buttonTopLeft");
        buttonTopLeft->setGeometry(QRect(750, 220, 31, 31));
        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(780, 220, 31, 31));
        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(750, 250, 31, 31));
        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName("toolButton_5");
        toolButton_5->setGeometry(QRect(780, 250, 31, 31));
        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName("toolButton_6");
        toolButton_6->setGeometry(QRect(810, 250, 31, 31));
        buttonBottomLeft = new QToolButton(centralwidget);
        buttonBottomLeft->setObjectName("buttonBottomLeft");
        buttonBottomLeft->setGeometry(QRect(750, 280, 31, 31));
        toolButton_8 = new QToolButton(centralwidget);
        toolButton_8->setObjectName("toolButton_8");
        toolButton_8->setGeometry(QRect(780, 280, 31, 31));
        buttonBottomRight = new QToolButton(centralwidget);
        buttonBottomRight->setObjectName("buttonBottomRight");
        buttonBottomRight->setGeometry(QRect(810, 280, 31, 31));
        buttonLeftUp = new QToolButton(centralwidget);
        buttonLeftUp->setObjectName("buttonLeftUp");
        buttonLeftUp->setGeometry(QRect(750, 320, 31, 31));
        toolButton_11 = new QToolButton(centralwidget);
        toolButton_11->setObjectName("toolButton_11");
        toolButton_11->setGeometry(QRect(780, 320, 31, 31));
        buttonRightUp = new QToolButton(centralwidget);
        buttonRightUp->setObjectName("buttonRightUp");
        buttonRightUp->setGeometry(QRect(810, 320, 31, 31));
        toolButton_13 = new QToolButton(centralwidget);
        toolButton_13->setObjectName("toolButton_13");
        toolButton_13->setGeometry(QRect(750, 350, 31, 31));
        toolButton_14 = new QToolButton(centralwidget);
        toolButton_14->setObjectName("toolButton_14");
        toolButton_14->setGeometry(QRect(780, 350, 31, 31));
        toolButton_15 = new QToolButton(centralwidget);
        toolButton_15->setObjectName("toolButton_15");
        toolButton_15->setGeometry(QRect(810, 350, 31, 31));
        buttonLeftDown = new QToolButton(centralwidget);
        buttonLeftDown->setObjectName("buttonLeftDown");
        buttonLeftDown->setGeometry(QRect(750, 380, 31, 31));
        toolButton_17 = new QToolButton(centralwidget);
        toolButton_17->setObjectName("toolButton_17");
        toolButton_17->setGeometry(QRect(780, 380, 31, 31));
        buttonRightDown = new QToolButton(centralwidget);
        buttonRightDown->setObjectName("buttonRightDown");
        buttonRightDown->setGeometry(QRect(810, 380, 31, 31));
        toolButton_16 = new QToolButton(centralwidget);
        toolButton_16->setObjectName("toolButton_16");
        toolButton_16->setGeometry(QRect(780, 450, 31, 31));
        buttonRightDown_2 = new QToolButton(centralwidget);
        buttonRightDown_2->setObjectName("buttonRightDown_2");
        buttonRightDown_2->setGeometry(QRect(810, 480, 31, 31));
        buttonRightUp_2 = new QToolButton(centralwidget);
        buttonRightUp_2->setObjectName("buttonRightUp_2");
        buttonRightUp_2->setGeometry(QRect(810, 420, 31, 31));
        toolButton_18 = new QToolButton(centralwidget);
        toolButton_18->setObjectName("toolButton_18");
        toolButton_18->setGeometry(QRect(780, 480, 31, 31));
        toolButton_19 = new QToolButton(centralwidget);
        toolButton_19->setObjectName("toolButton_19");
        toolButton_19->setGeometry(QRect(750, 450, 31, 31));
        toolButton_20 = new QToolButton(centralwidget);
        toolButton_20->setObjectName("toolButton_20");
        toolButton_20->setGeometry(QRect(810, 450, 31, 31));
        buttonLeftUp_2 = new QToolButton(centralwidget);
        buttonLeftUp_2->setObjectName("buttonLeftUp_2");
        buttonLeftUp_2->setGeometry(QRect(750, 420, 31, 31));
        toolButton_12 = new QToolButton(centralwidget);
        toolButton_12->setObjectName("toolButton_12");
        toolButton_12->setGeometry(QRect(780, 420, 31, 31));
        buttonLeftDown_2 = new QToolButton(centralwidget);
        buttonLeftDown_2->setObjectName("buttonLeftDown_2");
        buttonLeftDown_2->setGeometry(QRect(750, 480, 31, 31));
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
        buttonTopRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        buttonTopLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
        buttonBottomLeft->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        toolButton_8->setText(QString());
        buttonBottomRight->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        buttonLeftUp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        toolButton_11->setText(QString());
        buttonRightUp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        toolButton_13->setText(QString());
        toolButton_14->setText(QString());
        toolButton_15->setText(QString());
        buttonLeftDown->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        toolButton_17->setText(QString());
        buttonRightDown->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        toolButton_16->setText(QString());
        buttonRightDown_2->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        buttonRightUp_2->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        toolButton_18->setText(QString());
        toolButton_19->setText(QString());
        toolButton_20->setText(QString());
        buttonLeftUp_2->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        toolButton_12->setText(QString());
        buttonLeftDown_2->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
