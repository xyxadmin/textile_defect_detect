#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
public:
    bool value = false;
private:
    bool is_off = true;
    QPropertyAnimation* anim;
    int current_x;
    QBrush off_brush = QBrush(QColor(170, 157, 138));
    QBrush on_brush = QBrush(Qt::gray);
    QBrush off_circle_brush = QBrush(QColor(234, 198, 146));
    QBrush on_circle_brhsh = QBrush(Qt::green);
    QString off_state = "OFF";
    QString on_state = "ON";



signals:
    void stateChanged();
    void setState(bool status);
};

#endif // MYBUTTON_H
