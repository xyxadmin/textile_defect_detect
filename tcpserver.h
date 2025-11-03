#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QElapsedTimer>


class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);
public:
    void startListen(QString ip,int port);
private:
    QTcpServer* server;
    QByteArray receiveBuffer;
public:
    QTcpSocket* socket;
public slots:
public slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
public:
    void sendMessageToClient(QTcpSocket *clientSocket, QString msg);
signals:
    void dataReceived(QVector<int> receiveDataVector);
public:
    void processBuffer();

};

#endif // TCPSERVER_H
