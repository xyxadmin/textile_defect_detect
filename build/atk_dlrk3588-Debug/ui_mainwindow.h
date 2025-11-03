/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "chartshow.h"
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    MyButton *btn_cap;
    QLabel *label_2;
    QLabel *label_3;
    ChartShow *widget_chart;
    MyButton *btn_dete;
    QFrame *frame;
    QLabel *label_cputext;
    QLabel *label_cpu;
    QLabel *label_4;
    QFrame *frame_2;
    QSlider *hs_speed;
    QLabel *label_5;
    QLabel *label_speed;
    QLabel *label_7;
    QLabel *label_height;
    QSlider *hs_height;
    QSlider *hs_foreward;
    QLabel *label_8;
    QLabel *label_foreward;
    QPushButton *btn_exit;
    QLabel *label_ip;
    QLabel *label_wifi_connected;
    QLabel *label_test;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 611, 701));
        label->setMinimumSize(QSize(480, 640));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        btn_cap = new MyButton(centralwidget);
        btn_cap->setObjectName(QString::fromUtf8("btn_cap"));
        btn_cap->setGeometry(QRect(720, 380, 191, 80));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 390, 81, 51));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(970, 390, 81, 51));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        widget_chart = new ChartShow(centralwidget);
        widget_chart->setObjectName(QString::fromUtf8("widget_chart"));
        widget_chart->setGeometry(QRect(640, 10, 631, 361));
        btn_dete = new MyButton(centralwidget);
        btn_dete->setObjectName(QString::fromUtf8("btn_dete"));
        btn_dete->setGeometry(QRect(1050, 380, 191, 80));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(640, 480, 171, 171));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_cputext = new QLabel(frame);
        label_cputext->setObjectName(QString::fromUtf8("label_cputext"));
        label_cputext->setGeometry(QRect(3, 10, 161, 41));
        QFont font2;
        font2.setPointSize(22);
        label_cputext->setFont(font2);
        label_cputext->setFrameShape(QFrame::NoFrame);
        label_cputext->setAlignment(Qt::AlignCenter);
        label_cpu = new QLabel(frame);
        label_cpu->setObjectName(QString::fromUtf8("label_cpu"));
        label_cpu->setGeometry(QRect(0, 80, 91, 81));
        QFont font3;
        font3.setPointSize(18);
        label_cpu->setFont(font3);
        label_cpu->setFrameShape(QFrame::NoFrame);
        label_cpu->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 90, 71, 71));
        QFont font4;
        font4.setPointSize(43);
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 60, 91, 31));
        frame_2->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);"));
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(0);
        hs_speed = new QSlider(centralwidget);
        hs_speed->setObjectName(QString::fromUtf8("hs_speed"));
        hs_speed->setGeometry(QRect(829, 481, 301, 51));
        hs_speed->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { border: 0px solid #bbb; } \n"
"QSlider::sub-page:horizontal { background: rgb(235,97,0); border-radius: 0px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::add-page:horizontal { background: rgb(200,200, 200); border: 0px solid #777; border-radius: 2px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::handle:horizontal { background: rgb(255,153,102); border: 1px solid rgb(255,153,102); width: 25px; height:4px; border-radius: 7px; margin-top:2px; margin-bottom:2px; } \n"
"QSlider::handle:horizontal:hover { background: rgb(255,128,6); border: 1px solid rgba(102,102,102,102); border-radius: 7px; } \n"
"QSlider::sub-page:horizontal:disabled { background: #bbb; border-color: #999; } \n"
"QSlider::add-page:horizontal:disabled { background: #eee; border-color: #999; } \n"
"QSlider::handle:horizontal:disabled { background: #eee; border: 1px solid #aaa; border-radius: 4px; }"));
        hs_speed->setMinimum(0);
        hs_speed->setMaximum(100);
        hs_speed->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1150, 493, 51, 21));
        label_speed = new QLabel(centralwidget);
        label_speed->setObjectName(QString::fromUtf8("label_speed"));
        label_speed->setGeometry(QRect(1200, 493, 61, 21));
        label_speed->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1150, 554, 51, 21));
        label_height = new QLabel(centralwidget);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        label_height->setGeometry(QRect(1200, 553, 61, 21));
        label_height->setAlignment(Qt::AlignCenter);
        hs_height = new QSlider(centralwidget);
        hs_height->setObjectName(QString::fromUtf8("hs_height"));
        hs_height->setGeometry(QRect(829, 540, 301, 51));
        hs_height->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { border: 0px solid #bbb; } \n"
"QSlider::sub-page:horizontal { background: rgb(235,97,0); border-radius: 0px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::add-page:horizontal { background: rgb(200,200, 200); border: 0px solid #777; border-radius: 2px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::handle:horizontal { background: rgb(255,153,102); border: 1px solid rgb(255,153,102); width: 25px; height:4px; border-radius: 7px; margin-top:2px; margin-bottom:2px; } \n"
"QSlider::handle:horizontal:hover { background: rgb(255,128,6); border: 1px solid rgba(102,102,102,102); border-radius: 7px; } \n"
"QSlider::sub-page:horizontal:disabled { background: #bbb; border-color: #999; } \n"
"QSlider::add-page:horizontal:disabled { background: #eee; border-color: #999; } \n"
"QSlider::handle:horizontal:disabled { background: #eee; border: 1px solid #aaa; border-radius: 4px; }"));
        hs_height->setMinimum(0);
        hs_height->setMaximum(100);
        hs_height->setValue(1);
        hs_height->setOrientation(Qt::Horizontal);
        hs_foreward = new QSlider(centralwidget);
        hs_foreward->setObjectName(QString::fromUtf8("hs_foreward"));
        hs_foreward->setGeometry(QRect(829, 602, 301, 51));
        hs_foreward->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { border: 0px solid #bbb; } \n"
"QSlider::sub-page:horizontal { background: rgb(235,97,0); border-radius: 0px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::add-page:horizontal { background: rgb(200,200, 200); border: 0px solid #777; border-radius: 2px; margin-top:8px; margin-bottom:8px; } \n"
"QSlider::handle:horizontal { background: rgb(255,153,102); border: 1px solid rgb(255,153,102); width: 25px; height:4px; border-radius: 7px; margin-top:2px; margin-bottom:2px; } \n"
"QSlider::handle:horizontal:hover { background: rgb(255,128,6); border: 1px solid rgba(102,102,102,102); border-radius: 7px; } \n"
"QSlider::sub-page:horizontal:disabled { background: #bbb; border-color: #999; } \n"
"QSlider::add-page:horizontal:disabled { background: #eee; border-color: #999; } \n"
"QSlider::handle:horizontal:disabled { background: #eee; border: 1px solid #aaa; border-radius: 4px; }"));
        hs_foreward->setMinimum(0);
        hs_foreward->setMaximum(100);
        hs_foreward->setValue(1);
        hs_foreward->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1150, 614, 51, 21));
        label_foreward = new QLabel(centralwidget);
        label_foreward->setObjectName(QString::fromUtf8("label_foreward"));
        label_foreward->setGeometry(QRect(1200, 614, 61, 21));
        label_foreward->setAlignment(Qt::AlignCenter);
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(640, 659, 61, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_exit->setIcon(icon);
        btn_exit->setIconSize(QSize(50, 50));
        label_ip = new QLabel(centralwidget);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(990, 660, 171, 41));
        QFont font5;
        font5.setPointSize(17);
        label_ip->setFont(font5);
        label_ip->setAlignment(Qt::AlignCenter);
        label_wifi_connected = new QLabel(centralwidget);
        label_wifi_connected->setObjectName(QString::fromUtf8("label_wifi_connected"));
        label_wifi_connected->setGeometry(QRect(1180, 650, 51, 51));
        label_wifi_connected->setPixmap(QPixmap(QString::fromUtf8(":/picture/connected.png")));
        label_wifi_connected->setScaledContents(true);
        label_wifi_connected->setAlignment(Qt::AlignCenter);
        label_test = new QLabel(centralwidget);
        label_test->setObjectName(QString::fromUtf8("label_test"));
        label_test->setGeometry(QRect(710, 660, 291, 41));
        label_test->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\346\243\200\346\265\213\345\214\272\345\237\237", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213", nullptr));
        label_cputext->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">CPU</span></p></body></html>", nullptr));
        label_cpu->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#f57900;\">\342\204\203</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\275\254\351\200\237", nullptr));
        label_speed->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\351\253\230\345\272\246", nullptr));
        label_height->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\211\215\350\277\233", nullptr));
        label_foreward->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        btn_exit->setText(QString());
        label_ip->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\267\262\350\277\236\346\216\245", nullptr));
        label_wifi_connected->setText(QString());
        label_test->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201:   \346\255\243\345\234\250\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
