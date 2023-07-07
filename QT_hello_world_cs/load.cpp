#include "load.h"
#include "ui_load.h"
#include "set_context.h"

load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setFixedSize(1024,576);
    set_context(this,":/button/img/button/muban2.jpg");
    set_context(ui->widget,":/character/img/character/braver.png");

    time=new QTimer(this);
    time->start(30);
    connect(time,&QTimer::timeout,this,&load::set_loadbar);
    this->setWindowTitle("OLIVER");
}

void load::set_loadbar()
{
    int index=ui->loadbar->value();
    index++;
    if(index>100)
    {
        time->stop();
        emit full();
        return;
    }
    ui->loadbar->setValue(index);
    ui->widget->setGeometry(9*index,250,100,100);
}
void load::set_loadbar_text(int n)
{
    QString des="正在前往";
    des.append(Oliver::mapi[n]);
    ui->destination->setText(des);
}
load::~load()
{
    delete ui;
}
