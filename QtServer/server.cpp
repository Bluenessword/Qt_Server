#include "server.h"

//构造函数  在实例化时执行
Server::Server(int port)
{
    listen(QHostAddress::Any,port);
}

void Server::incomingConnection(qintptr handle)
{
    socket=new QTcpSocket(this);
    socket->setSocketDescriptor(handle);
    connect(socket,&QTcpSocket::readyRead,this,&Server::receiveMessage);

    QString str = socket->peerAddress().toString().split(":")[3] + "上线";

    emit giveMessage(str,1);
}

void Server::receiveMessage()
{
    //c++ 数组中空的部分用\0

    QByteArray arr = socket->readAll();
    QString str = arr.data();

    emit giveMessage(str,2);
}
