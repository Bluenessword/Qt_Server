#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>
#include <QString>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

private slots:
    void on_connect_clicked();
    void receiveMessage();

    void on_send_clicked();

private:
    Ui::Client *ui;
    QTcpSocket *socket;

};

#endif // CLIENT_H
