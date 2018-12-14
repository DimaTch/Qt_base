#include "home.h"
#include "ui_home.h"
#include <QDebug>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(btn_clk()));
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

void Home::btn_clk(){
    if (state == false) {
        state = true;
    }
    else {
        state = false;
    }
    repaint();
}


Home::~Home()
{
    delete ui;
}
