#include "mybutton.h"

MyButton::MyButton(QWidget *parent)
    : QWidget{parent}
{
    current_x = width()/2-height()-5;
    anim = new QPropertyAnimation(this);
    anim->setTargetObject(this);
    anim->setStartValue(height()/2);
    anim->setEndValue(width() - height()/2);
    anim->setEasingCurve(QEasingCurve::InOutElastic);
    anim->setDuration(50);
    connect(anim,&QPropertyAnimation::valueChanged,this,[=](const QVariant &value){
        current_x = value.toInt();
        update();
    });
}

void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(is_off ? off_brush : on_brush);
    int radius = this->height() / 2;
    //圆弧矩形
    painter.drawRoundedRect(rect(),radius,radius);
    //圆
    painter.setBrush(is_off ? off_circle_brush : on_circle_brhsh);
    painter.drawEllipse(is_off ? QPoint(current_x,radius) : QPoint(current_x,radius),radius - radius / 6,radius - radius / 6);
    //text
    painter.setPen(QPen(Qt::white));
    painter.setFont(QFont("行楷",height() / 4));
    painter.drawText(QRect(0,0,width(),height()),Qt::AlignCenter,is_off ? off_state : on_state);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit stateChanged();
        value = !value;
        emit setState(value);
        is_off ? anim->setDirection(QAbstractAnimation::Forward) : anim->setDirection(QAbstractAnimation::Backward);
        is_off = !is_off;
        anim->start();
        update();
        return;
    }
    QWidget::mousePressEvent(event);
}

void MyButton::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    anim->setStartValue(height()/2);
    anim->setEndValue(width() - height()/2);
}
