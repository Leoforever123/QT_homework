#include "rolig_sea.h"
#include "ui_rolig_sea.h"
#include "set_context.h"
#include "oliver.h"
#include <QDialog>
#include "outsea.h"
#include "dialog.h"

QString rolig_sea::seaimg[4]={
    ":/sea/img/map/rolig_village_beach1.png",
    ":/sea/img/map/rolig_village_beach2.png",
    ":/sea/img/map/rolig_village_beach3.png",
    ":/sea/img/map/rolig_village_beach4.png"
};
rolig_sea::rolig_sea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rolig_sea)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    //设置标题
    this->setWindowTitle("OLIVER");
    //设置背景
    this->setFixedSize(1024,576);
    set_context(this,seaimg[0]);
    set_context(ui->fisherman,":/character/img/character/fishman.png");
    //初始化人物
    Oliver::pos=1;
    Oliver *oliver=new Oliver(this);
    //设置状态栏
    set_status(ui->statusbar,this);
    //设置按钮背景
    ui->back->setGeometry(840,180,150,30);
    ui->back->setFixedSize(150,50);
    ui->back->setFlat(true);
    ui->back->setStyleSheet("color:white");
    ui->backwid->setFixedSize(150,50);
    ui->backwid->setGeometry(840,180,150,30);
    set_context(ui->backwid,":/button/img/button/longbutton.png");
    ui->backwid->lower();

    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    connect(ui->out_sea,&QPushButton::clicked,[this](){
        Oliver::audio->play(2);
        outsea* out=new outsea(this);
        Oliver::courage_condition=1;
        out->exec();
    });

    seatimer=new QTimer(this);
    connect(seatimer,&QTimer::timeout,this,&rolig_sea::sea_change);
    sea=0;
    seatimer->start(600);

}

rolig_sea::~rolig_sea()
{
    delete ui;
}

void rolig_sea::on_back_clicked()
{
    Oliver::audio->play(2);
    QWidget* par=this->parentWidget();
    par->show();
    Oliver::pos=0;
    this->hide();
    delete this;
}

void rolig_sea::sea_change(){
    set_context(this,seaimg[sea]);
    sea = (sea+1)%4;
}


void rolig_sea::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    dia->set_text(5,1);
    dia->exec();
}

