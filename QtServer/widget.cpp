#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_openBtn_clicked()
{
    int port = ui->portle->text().toInt();
    server = new Server(port);
    connect(server,&Server::giveMessage,this,&Widget::myGiveMessage);
}

void Widget::myGiveMessage(QString str, int state)
{
    if(state == 1)
    {
        ui->logList->addItem(str);
    }
    else if(state == 2)
    {
        ui->rMessageText->setText(str);
    }

}

void Widget::on_sendBtn_clicked()
{
    QByteArray arr = ui->sMessageText->toPlainText().toUtf8();
    server->socket->write(arr);
}
