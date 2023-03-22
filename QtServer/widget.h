#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "server.h"
#include <QByteArray>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_openBtn_clicked();
    void myGiveMessage(QString str,int state);

    void on_sendBtn_clicked();

private:
    Ui::Widget *ui;
    Server *server;
};

#endif // WIDGET_H
