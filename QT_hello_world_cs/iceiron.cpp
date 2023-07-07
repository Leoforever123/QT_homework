#include "iceiron.h"
#include "ui_iceiron.h"
#include "set_context.h"
#include "getmagic.h"
#include <QMessageBox>
#include "oliver.h"
iceiron::iceiron(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iceiron)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    set_context(this,":/map/img/map/iskalde_landet.jpg");
    set_context(ui->box,":/button/img/box/god_box.png");
    this->setWindowTitle("OLIVER");
}

iceiron::~iceiron()
{
    delete ui;
}

void iceiron::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->parentWidget()->show();
    this->hide();
    delete this;
}


void iceiron::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::skill_type==2)
    {
        QMessageBox::information(this,"提醒","你已经取走里面的宝物了！");
        return;
    }
    Oliver::skill_type=2;
    getmagic *magic=new getmagic(this);
    magic->exec();
}

