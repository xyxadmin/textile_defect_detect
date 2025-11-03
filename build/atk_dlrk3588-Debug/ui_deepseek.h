/********************************************************************************
** Form generated from reading UI file 'deepseek.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEEPSEEK_H
#define UI_DEEPSEEK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeepSeek
{
public:
    QWidget *widget;
    QPushButton *btn_dsexit;
    QTextEdit *textEdit_dialog;
    QTextEdit *textEdit_inputtods;
    QPushButton *btn_sendtods;

    void setupUi(QWidget *DeepSeek)
    {
        if (DeepSeek->objectName().isEmpty())
            DeepSeek->setObjectName(QString::fromUtf8("DeepSeek"));
        DeepSeek->resize(746, 650);
        widget = new QWidget(DeepSeek);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 741, 41));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        btn_dsexit = new QPushButton(widget);
        btn_dsexit->setObjectName(QString::fromUtf8("btn_dsexit"));
        btn_dsexit->setGeometry(QRect(630, 4, 89, 31));
        btn_dsexit->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 92, 0);"));
        textEdit_dialog = new QTextEdit(DeepSeek);
        textEdit_dialog->setObjectName(QString::fromUtf8("textEdit_dialog"));
        textEdit_dialog->setGeometry(QRect(10, 60, 731, 211));
        textEdit_inputtods = new QTextEdit(DeepSeek);
        textEdit_inputtods->setObjectName(QString::fromUtf8("textEdit_inputtods"));
        textEdit_inputtods->setGeometry(QRect(10, 280, 611, 41));
        btn_sendtods = new QPushButton(DeepSeek);
        btn_sendtods->setObjectName(QString::fromUtf8("btn_sendtods"));
        btn_sendtods->setGeometry(QRect(630, 280, 111, 41));

        retranslateUi(DeepSeek);

        QMetaObject::connectSlotsByName(DeepSeek);
    } // setupUi

    void retranslateUi(QWidget *DeepSeek)
    {
        DeepSeek->setWindowTitle(QCoreApplication::translate("DeepSeek", "Form", nullptr));
        btn_dsexit->setText(QCoreApplication::translate("DeepSeek", "\351\200\200\345\207\272", nullptr));
        btn_sendtods->setText(QCoreApplication::translate("DeepSeek", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeepSeek: public Ui_DeepSeek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEEPSEEK_H
