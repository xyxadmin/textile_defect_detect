/********************************************************************************
** Form generated from reading UI file 'setting_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_WIDGET_H
#define UI_SETTING_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting_Widget
{
public:
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *btn_exit;
    QPushButton *btn_cancel;

    void setupUi(QWidget *Setting_Widget)
    {
        if (Setting_Widget->objectName().isEmpty())
            Setting_Widget->setObjectName(QString::fromUtf8("Setting_Widget"));
        Setting_Widget->resize(618, 458);
        Setting_Widget->setMaximumSize(QSize(800, 600));
        label = new QLabel(Setting_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 30, 131, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Setting_Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 90, 131, 31));
        QFont font1;
        font1.setPointSize(15);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Setting_Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 260, 131, 41));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Setting_Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 160, 111, 31));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(Setting_Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(440, 90, 111, 41));
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox_2 = new QSpinBox(Setting_Widget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(441, 160, 111, 41));
        spinBox_2->setFont(font);
        spinBox_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Setting_Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 80, 111, 51));
        QFont font2;
        font2.setPointSize(14);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(Setting_Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 150, 111, 51));
        pushButton_2->setFont(font2);
        btn_exit = new QPushButton(Setting_Widget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(450, 380, 81, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/picture/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_exit->setIcon(icon);
        btn_exit->setIconSize(QSize(64, 64));
        btn_cancel = new QPushButton(Setting_Widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(150, 410, 89, 41));

        retranslateUi(Setting_Widget);

        QMetaObject::connectSlotsByName(Setting_Widget);
    } // setupUi

    void retranslateUi(QWidget *Setting_Widget)
    {
        Setting_Widget->setWindowTitle(QCoreApplication::translate("Setting_Widget", "Form", nullptr));
        label->setText(QCoreApplication::translate("Setting_Widget", "\345\217\257\350\247\206\345\214\226", nullptr));
        label_4->setText(QCoreApplication::translate("Setting_Widget", "\346\226\207\345\255\227\345\244\247\345\260\217", nullptr));
        label_5->setText(QCoreApplication::translate("Setting_Widget", "\346\243\200\346\265\213\350\243\205\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("Setting_Widget", "\346\243\200\346\265\213\346\241\206\345\244\247\345\260\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Setting_Widget", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Setting_Widget", "\346\243\200\346\265\213\346\241\206\351\242\234\350\211\262", nullptr));
        btn_exit->setText(QString());
        btn_cancel->setText(QCoreApplication::translate("Setting_Widget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setting_Widget: public Ui_Setting_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_WIDGET_H
