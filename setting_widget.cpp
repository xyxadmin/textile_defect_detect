#include "setting_widget.h"
#include "ui_setting_widget.h"

Setting_Widget::Setting_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Setting_Widget)
{
    ui->setupUi(this);
    connect(ui->btn_cancel,&QPushButton::clicked,this,&Setting_Widget::closeSetting);

}

Setting_Widget::~Setting_Widget()
{
    delete ui;
}

void Setting_Widget::closeSetting()
{
    this->close();
}
