#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPainter>


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

    bool state = false;
    QPainter painter;
    void paintEvent(QPaintEvent *event);


private slots:
    void btn_clk();
};

#endif // HOME_H
