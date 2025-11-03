#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QTimer>
#include <QMessageBox>

#include <cmath>

#include "camerinfer.h"
#include "mainwindow.h"
#include "shellcontroller.h"
#include "datetime.h"
#include "tcpserver.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateFrame(QVector<float> confidences, double fps);
    void onOpenCap();
    void onOpenDete();
    void onCputemp();
    void onSpeedChanged(int value);
    void onHeightChanged(int value);
    void onForewardChanged(int value);
    void onClickedExit();
    void onReceivedTcpData(QVector<int> tcpData);
    void onsetMotorValue();
    void onGetClsId(int id);
private:
    void initComponents();
private:
    Ui::MainWindow *ui;
    CamerInfer* infer;
    QThread* thread_infer;
    ShellController* shell;
    QThread* thread_shell;
    QTimer* timer;
    DateTime* dateTime;
    QThread* thread_datetime;
    TCPServer* server;
    QThread* thread_server;
    QStringList tcpDataList;
    QString serverIP = "192.168.4.1";
    int serverPort = 8080;




};
#endif // MAINWINDOW_H
