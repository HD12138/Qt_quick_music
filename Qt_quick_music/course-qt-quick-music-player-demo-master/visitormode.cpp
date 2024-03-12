#include "visitormode.h"
#include "ui_visitormode.h"

VisitorMode::VisitorMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisitorMode)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("提示");
    time = 120;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &VisitorMode::TimeChange);
}

VisitorMode::~VisitorMode()
{
    delete ui;
}

void VisitorMode::TimeChange()
{
    time--;
    QString TIME = "倒计时：" + QString::number(time) + "s";
    ui->label_time->setText(TIME);
    if(time == 0)
        timer->stop();

}

