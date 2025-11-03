#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1280,720);
    infer = new CamerInfer;
    infer->set_label(ui->label);
    thread_infer = new QThread(this);
    infer->moveToThread(thread_infer);
    shell = new ShellController;
    thread_shell = new QThread(this);
    shell->moveToThread(thread_shell);
    dateTime = new DateTime;
    thread_datetime = new QThread(this);
    dateTime->moveToThread(thread_datetime);
    server = new TCPServer;
    thread_server = new QThread(this);
    server->moveToThread(thread_server);
    initComponents();
    connect(thread_infer, &QThread::started, infer, &CamerInfer::processFrame,Qt::QueuedConnection);
    connect(infer,&CamerInfer::frameProcessed,this,&MainWindow::updateFrame,Qt::QueuedConnection);
    connect(ui->btn_cap,&MyButton::stateChanged,this,&MainWindow::onOpenCap);
    connect(ui->btn_dete,&MyButton::stateChanged,this,&MainWindow::onOpenDete);
    connect(timer,&QTimer::timeout,this,&MainWindow::onCputemp);
    connect(ui->hs_speed,&QSlider::valueChanged,this,&MainWindow::onSpeedChanged);
    connect(ui->hs_height,&QSlider::valueChanged,this,&MainWindow::onHeightChanged);
    connect(ui->hs_foreward,&QSlider::valueChanged,this,&MainWindow::onForewardChanged);
    connect(ui->btn_exit,&QPushButton::clicked,this,&MainWindow::onClickedExit);
    connect(server,&TCPServer::dataReceived,this,&MainWindow::onReceivedTcpData,Qt::QueuedConnection);
    connect(ui->hs_speed,&QSlider::valueChanged,this,&MainWindow::onsetMotorValue);
    connect(ui->hs_height,&QSlider::valueChanged,this,&MainWindow::onsetMotorValue);
    connect(ui->hs_foreward,&QSlider::valueChanged,this,&MainWindow::onsetMotorValue);
    // connect(thread_server, &QThread::started, server,
    //         [this](){ server->startListen(serverIP, serverPort); },
    //         Qt::QueuedConnection);
    connect(infer,&CamerInfer::get_cls_id,this,&MainWindow::onGetClsId);
    thread_infer->start(QThread::TimeCriticalPriority);
    thread_shell->start();
    thread_datetime->start();
    thread_server->start(QThread::LowPriority);
    timer->start(55);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::updateFrame(QVector<float> confidences, double fps)
{
    //std::cout << "========================================================FPS=================================" << fps << std::endl;
    float mean_confidence = std::accumulate(confidences.begin(),confidences.end(),0.0)/confidences.size();
    //std::cout << "=====================================" << mean_confidence + 10.77 << "==============================================" << std::endl;
    ui->widget_chart->updateChart((int)std::round(mean_confidence),(int)std::round(fps));
}

void MainWindow::onOpenCap()
{
    int cap_value = ui->btn_cap->value;
    if(cap_value == 1){
        infer->isOpenCap(false);
        ui->label->clear();
        ui->label->setText("视频检测区域");
        disconnect(infer,&CamerInfer::frameProcessed,this,&MainWindow::updateFrame);
    }else if(cap_value == 0){
        infer->set_label(ui->label);
        infer->isOpenCap(true);
        connect(infer,&CamerInfer::frameProcessed,this,&MainWindow::updateFrame,Qt::QueuedConnection);
    }
}

void MainWindow::onOpenDete()
{
    int detection_value = ui->btn_dete->value;
    if(detection_value == 1){
        infer->isOpenDetec(false);
    }else if(detection_value == 0){
        infer->isOpenDetec(true);
    }
}

void MainWindow::onCputemp()
{
    shell->setCommand("cat /sys/class/thermal/thermal_zone0/temp");
    QString temp = QString::fromStdString(shell->getResult());
    temp.insert(2,".");
    ui->label_cpu->setText(temp);
    //shell->setCommand("date");
    //ui->label_date_time->setText(dateTime->pareseDateTime(QString::fromStdString(shell->getResult())));
    timer->start(1000);
}



void MainWindow::onSpeedChanged(int value)
{
    ui->label_speed->setText(QString::number(value).append("%"));
}

void MainWindow::onHeightChanged(int value)
{
    ui->label_height->setText(QString::number(value).append("%"));
}

void MainWindow::onForewardChanged(int value)
{
    ui->label_foreward->setText(QString::number(value).append("%"));
}

void MainWindow::onClickedExit()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("退出程序");
    msgBox.setText("确定要退出程序吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.button(QMessageBox::Yes)->setText("确认");
    msgBox.button(QMessageBox::No)->setText("取消");
    msgBox.setStyleSheet(
        "QMessageBox {"
        "   background-color: #E0F7FA;"      // 设置背景颜色
        "}"
        "QLabel {"
        "   color: red;"                 // 字体红色
        "   font-size: 16px;"             // 字体大小
        "   qproperty-alignment: AlignCenter;"  // 文本居中
        "   min-width: 500px;"            // 设置内容区域最小宽度
        "   min-height: 200px;"           // 设置内容区域最小高度
        "}"
        "QPushButton {"
        "   min-width: 80px;"             // 设置按钮最小宽度
        "   min-height: 30px;"            // 设置按钮最小高度
        "}"
        );
    int ret = msgBox.exec();

    if (ret == QMessageBox::Yes) {
        qApp->quit();  // 退出应用程序
    }
}

void MainWindow::onReceivedTcpData(QVector<int> tcpData)
{

    ui->label_test->clear();
    ui->hs_speed->setValue(tcpData[0]);
    ui->hs_height->setValue(tcpData[1]);
    ui->hs_foreward->setValue(tcpData[2]);
    //ui->label_test->setText(QString::number(tcpData[0])+QString::number(tcpData[1])+QString::number(tcpData[2]));
    //server->sendMessageToClient(server->socket,QString::number(tcpData[0])+"|"+QString::number(tcpData[1])+"|"+QString::number(tcpData[2]));
}

void MainWindow::onsetMotorValue()
{
    // 添加原子锁
    static QAtomicInt lock(0);
    if(!lock.testAndSetRelaxed(0, 1)) return;

    // 添加发送锁防止重复发送
    static bool isSending = false;
    if(isSending) return;
    isSending = true;

    // QString sendMsg = "convey:"+QString::number(ui->hs_speed->value()) + "," + "lift:"+
    //                   QString::number(ui->hs_height->value()) + "," + "forward:"+
    //                   QString::number(ui->hs_foreward->value());

    //server->sendMessageToClient(server->socket, sendMsg);

    isSending = false;

    lock.storeRelease(0);
}

void MainWindow::onGetClsId(int id)
{

    if(id == 2){
        //server->sendMessageToClient(server->socket,"2");
    }
}

void MainWindow::initComponents()
{
    infer->isOpenCap(false);
    infer->isOpenDetec(false);
    ui->label->clear();
    ui->label->setText("视频检测区域");
    shell->setCommand("wifi.sh");
    shell->getResult();
}
