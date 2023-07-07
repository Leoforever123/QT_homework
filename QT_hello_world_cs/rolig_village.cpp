#include "rolig_village.h"
#include "ui_rolig_village.h"
#include "set_context.h"
#include <QFont>
#include <QDebug>
#include <QStatusBar>
#include "oliver.h"
#include <QString>
#include <QLabel>
#include "rolig_sea.h"
#include "ironmanhouse.h"
#include "magichouse.h"
#include "shop.h"
#include "dialog.h"
#include <QAction>
#include "settings.h"
#include "file.h"
#include <QPoint>

QString rolig_village::bgimg[5] ={
    ":/water/img/water/water1.jpg",
    ":/water/img/water/water2.jpg",
    ":/water/img/water/water3.jpg",
    ":/water/img/water/water4.jpg",
    ":/water/img/water/water5.jpg"
};
rolig_village::rolig_village(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rolig_village)
{
    bg_pos=0;
    bgtimer = new QTimer(this);
    ui->setupUi(this);
    init();
    Oliver *oliver=new Oliver(this);
    set_status(ui->statusbar,this);
    connect(bgtimer,&QTimer::timeout,this,&rolig_village::bg_animation);
    bgtimer->start(50);
}


void rolig_village::init()
{
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    //**********初始化场景**********//
    //初始化窗口参数
    this->setFixedSize(1024,576);
    this->setWindowTitle("OLIVER");

    //初始化背景
    set_context(this,context_name);

    //***********初始化按钮*********//
    //grandma
    ui->grandma->setStyleSheet("color:rgb(117,111,168)");
    ui->grandma->setGeometry(620,460,60,28);
    //crazyman
    ui->crazyman->setGeometry(220,385,60,28);
    ui->crazyman->setStyleSheet("color:red");
    //ironman's
    ui->ironmanhouse->setGeometry(165,190,60,28);
    ui->ironmanhouse->setStyleSheet("color:white");
    ui->ironmanhouse->setFlat(true);
    //magichouse
    ui->magichouse->setGeometry(482,190,60,28);
    ui->magichouse->setStyleSheet("color:white");
    ui->magichouse->setFlat(true);
    //shop
    ui->shop->setGeometry(800,190,90,28);
    ui->shop->setText("商  店");
    ui->shop->setStyleSheet("color:white");
    ui->shop->setFlat(true);
    //gotosea
    ui->gotosea->setGeometry(40,370,150,50);
    ui->gotosea->setStyleSheet("color:white");
    ui->gotosea->setFlat(true);
    //初始化按钮背景
    set_button_context(ui->ironmanhouse,this,":/button/img/button/longbutton.png");
    set_button_context(ui->magichouse,this,":/button/img/button/longbutton.png");
    set_button_context(ui->shop,this,":/button/img/button/longbutton.png");
    QWidget* muban=new QWidget(this);
    muban->setFixedSize(ui->gotosea->size());
    muban->setGeometry(40,395,150,50);
    set_context(muban,":/button/img/button/longbutton.png");
    muban->lower();

    //初始化选项栏
    connect(ui->actionset,&QAction::triggered,this,[this](){
        Oliver::audio->play(2);
        dialog* dia=new dialog(this);
        dia->set_text(1,2);
        dia->exec();
    });
    connect(ui->note,&QAction::triggered,this,[this](){
        Oliver::audio->play(2);
        dialog* dia=new dialog(this);
        dia->set_text(2,2);
        dia->exec();
    });
    connect(ui->actionsettings,&QAction::triggered,this,[this](){
        Oliver::audio->play(2);
        settings* set=new settings(this);
        set->exec();
    });
    connect(ui->actionexit,&QAction::triggered,[this](){
        Oliver::audio->play(2);
        Oliver::whethernew=1;
        setfile("data.txt");
        delete this;
    });
}
rolig_village::~rolig_village()
{
    delete ui;
}

void rolig_village::on_gotosea_clicked()
{
    Oliver::audio->play(2);
    rolig_sea * sea=new rolig_sea(this);
    sea->show();
    this->hide();
}


void rolig_village::on_ironmanhouse_clicked()
{
    Oliver::audio->play(2);
    ironmanhouse* ironman=new ironmanhouse(this);
    ironman->show();
    this->hide();
}


void rolig_village::on_magichouse_clicked()
{
    Oliver::audio->play(2);
    magichouse* magic=new magichouse(this);
    magic->show();
    this->hide();
    Oliver::pos=3;
}


void rolig_village::on_shop_clicked()
{
    Oliver::audio->play(2);
    this->hide();
    auto sho=new shop(this);
    sho->show();
}


void rolig_village::on_grandma_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    if(Oliver::metwithNPC[4]==0)
    {
        dia->set_text(6,1);
        Oliver::metwithNPC[4]=1;
    }
    else
    {
        dia->set_text(7,1);
    }
    dia->exec();
}


void rolig_village::on_crazyman_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    dia->set_text(8,1);
    dia->exec();
}

void rolig_village::bg_animation(){
    set_context(this,bgimg[bg_pos]);
    bg_pos = (bg_pos+1)%5;
}
