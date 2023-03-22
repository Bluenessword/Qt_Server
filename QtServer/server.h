#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(int port);
    void incomingConnection(qintptr handle);
    QTcpSocket *socket;

private slots:
    void receiveMessage();

//自定义信号 传数据
signals:
    //str为获取的字符串  state为状态码  1表示用户连接信息  2表示收到的信息
    void giveMessage(QString str,int state);

};

#endif // SERVER_H
