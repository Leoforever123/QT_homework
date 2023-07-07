#include "getmagic.h"
#include "ui_getmagic.h"
#include "set_context.h"
#include "oliver.h"

getmagic::getmagic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getmagic)
{
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    ui->setupUi(this);
    this->setFixedSize(405,473);
    set_context(this,":/button/img/button/muban.jpg");
    if(Oliver::skill_type==1)
    set_context(ui->magicbook,":/weapon&book/img/weapon&book/magicbook1.png");
    else
    {
    set_context(ui->magicbook,":/weapon&book/img/weapon&book/magicbook2.png");
    ui->label->setText("你获得了“灵魂灼烧”");
    }
    this->setWindowTitle("OLIVER");
}


getmagic::~getmagic()
{
    delete ui;
}

void getmagic::on_toolButton_clicked()
{
    Oliver::audio->play(2);
    delete this;
}

