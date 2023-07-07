#include "getsword.h"
#include "ui_getsword.h"
#include "set_context.h"

getsword::getsword(QWidget *parent,int sword) :
    QDialog(parent),
    ui(new Ui::getsword)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setFixedSize(405,473);
    set_context(this,":/button/img/button/muban.jpg");
    if(sword==1)
    set_context(ui->sword,":/weapon&book/img/weapon&book/longsword.png");
    else
    {
        ui->label->setText("你获得了火焰剑！");
        set_context(ui->sword,":/weapon&book/img/weapon&book/firesword.png");
    }
    this->setWindowTitle("OLIVER");

}

getsword::~getsword()
{
    delete ui;
}

void getsword::on_quit_clicked()
{
    Oliver::audio->play(2);
    delete this;
}

