#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);
    socket = new QTcpSocket(this);
}

void TCPServer::startListen(QString ip, int port)
{
    bool ret = server->listen(QHostAddress(ip.trimmed()),port);
    if(!ret){
        qDebug() << "ip or port format error";
        return;
    }
    connect(server,&QTcpServer::newConnection,this,&TCPServer::onNewConnection);
}

void TCPServer::onNewConnection()
{
    socket = server->nextPendingConnection();
    qDebug() << "新连接 ---- >" << socket->IPv4Protocol;
    connect(socket,&QTcpSocket::readyRead,this,&TCPServer::onReadyRead);

}

void TCPServer::onReadyRead()
{
    socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        receiveBuffer = socket->readAll();
        processBuffer();

    }
}

void TCPServer::processBuffer()
{

    // 添加处理超时机制
    static QElapsedTimer processTimer;
    if(processTimer.isValid() && processTimer.elapsed() < 10){
        return; // 10ms内不重复处理
    }
    processTimer.start();
    // 查找足够的分隔符
    int commaCount = receiveBuffer.count(',');
    if (commaCount < 2) return;

    // 分割前三段数据
    QList<QByteArray> parts = receiveBuffer.split(',');

    QVector<int> values;

    for (int i = 0; i < 3 ; ++i) {
        bool ok;
        int val = parts[i].trimmed().toInt(&ok);
        if (ok) {
            values.append(val);
        }
    }
    emit dataReceived(values);

    receiveBuffer.clear();

}


void TCPServer::onClientDisconnected()
{
    socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        socket->deleteLater();
        qInfo() << "客户端断开连接:" << socket->peerAddress().toString();
    }
}

void TCPServer::sendMessageToClient(QTcpSocket *clientSocket, QString msg)
{
    if (socket && socket->state() == QAbstractSocket::ConnectedState) {
        clientSocket->write(msg.toUtf8()+"\r\n");
        clientSocket->flush();
    }
}
