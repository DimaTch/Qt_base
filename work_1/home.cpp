#include "home.h"
#include "ui_home.h"
#include <QDebug>

Home::Home(QWidget *parent) :
    QWidget(parent), state(false),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    ptr_tcpsocket = new QTcpSocket();



    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(btn_clk()));
    connect(ptr_tcpsocket, SIGNAL(connected()),SLOT(slotConnected()));
}

void Home::paintEvent(QPaintEvent* event){

    painter.begin(this);
    if (state==false)
        painter.setBrush(QBrush(Qt::red,Qt::SolidPattern));
    else
        painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(ui->label->geometry());
    painter.end();
}

void Home::slotConnected(){
    state = true;
    repaint();

}
void Home::btn_clk(){

    strHost = ui->lineEdit->text();
    nPort = ui->lineEdit_2->text().toInt();
    ptr_tcpsocket->connectToHost(strHost, nPort);


//    if (state == false) {
//        state = true;
//    }
//    else {
//        state = false;
//    }
//    repaint();

}


Home::~Home()
{
    delete ui;
}
