#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPainter>
#include <QtNetwork>



namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();

private:
    Ui::Home *ui;

    bool state;
    QPainter painter;
    QTcpSocket* ptr_tcpsocket;
    QString strHost;
    int nPort;

    void paintEvent(QPaintEvent *event);





private slots:
    void btn_clk();
    void slotConnected();
};

#endif // HOME_H
