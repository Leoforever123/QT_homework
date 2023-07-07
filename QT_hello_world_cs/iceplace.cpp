#include "iceplace.h"
#include "ui_iceplace.h"
#include "set_context.h"
#include "oliver.h"
#include "dialog.h"
#include <QTimer>
#include <QDateTime>
#include "iceiron.h"

iceplace::iceplace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iceplace)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    //初始化窗口参数
    this->setFixedSize(1024,576);
    this->setWindowTitle("OLIVER");

    //设置背景
    set_context(this,":/map/img/map/ice.jpg");

    //初始化主角
    Oliver* oliver=new Oliver(this);
    set_status(ui->statusbar,this);

    //初始化地堡和守卫
    set_context(ui->widget,":/map/img/map/iceberg.png");
    set_context(ui->widget_2,":/character/img/character/icesoldier_r.png");
    set_context(ui->widget_3,":/character/img/character/icesoldier.png");
}

iceplace::~iceplace()
{
    delete ui;
}


void iceplace::on_entericeberg_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::sword_type!=2)
    {
        dialog *dia=new dialog(this);
        dia->set_text(11,1);
        dia->exec();
    }
    else
    {
        ui->widget_2->setGeometry(310,310,120,120);
        ui->widget_3->setGeometry(490,310,120,120);
        dialog *dia=new dialog(this);
        dia->set_text(12,1);
        dia->exec();
        iceiron* ice=new iceiron(this);
        ice->show();
    }

}

