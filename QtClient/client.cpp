#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}

//连接服务端
void Client::on_connect_clicked()
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ui->ip->text(),ui->port->text().toInt());
    connect(socket,&QTcpSocket::readyRead,this,&Client::receiveMessage);
}

void Client::receiveMessage()
{
    QByteArray arr = socket->readAll();
    QString str = arr.data();
    ui->rMessage->setText(str);
    if(str=="111")
    {
        this->hide();
    }
    else if(str=="222")
    {
        this->show();
    }
}

void Client::on_send_clicked()
{
    QString str = ui->sMessage->toPlainText();
    socket->write(str.toUtf8());
}
