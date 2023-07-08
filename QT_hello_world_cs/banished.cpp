#include "banished.h"
#include "ui_banished.h"
#include "set_context.h"
#include "oliver.h"
#include "dialog.h"
#include <QTimer>
#include "end.h"
#include "mainwindow.h"

banished::banished(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::banished)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    //初始化窗口参数
    this->setFixedSize(1024,576);
    this->setWindowTitle("OLIVER");
    //设置背景
    set_context(this,":/map/img/map/banished.jpg");
    //初始化主角
    Oliver* oliver=new Oliver(this);
    set_status(ui->statusbar,this);
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton->hide();
    if(Oliver::metwithNPC[6]==0){
        ui->pushButton->show();
    //初始化邪教徒
    set_context(ui->widget,":/character/img/character/badman.png");
    set_context(ui->widget_2,":/character/img/character/badman.png");
    set_context(ui->widget_3,":/character/img/character/badman_r.png");
    set_context(ui->widget_4,":/character/img/character/badman.png");
    set_context(ui->widget_5,":/character/img/character/badman_r.png");
    set_context(ui->widget_6,":/character/img/character/badman_r.png");
    set_context(ui->widget_7,":/icon/img/icon/magicshake.png");
    set_context(ui->widget_8,":/character/img/character/dacula.png");
    ui->widget_7->hide();

    //设置按钮
    ui->widget_8->hide();
    time=new QTimer(this);
    postimer = new QTimer(this);
    connect(time,&QTimer::timeout,this,&banished::set);
    connect(postimer,&QTimer::timeout,this,&banished::set_pos);

    //设置播放器
    MainWindow::player->stop();
    MainWindow::player->setSource(QUrl("qrc:/mp3/mp3/06 - Hornet.mp3"));
    MainWindow::player->play();
    }
}

banished::~banished()
{
    delete ui;
}
//303132Oliver与一个手下的对话。33343536与satan等人的对话以及战斗。37追随者献祭自己。38394041与Feardorchae的对话
void banished::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia1=new dialog(this);
    dialog* dia2=new dialog(this);
    dialog* dia3=new dialog(this);
    dia1->set_text(30,1);
    dia1->exec();
    dia2->set_text(31,1);
    dia2->exec();
    dia3->set_text(32,1);
    dia3->exec();
    ui->pushButton_2->show();
    ui->pushButton->hide();
    ui->widget_5->hide();
}


void banished::on_pushButton_2_clicked()
{
    Oliver::audio->play(2);
    dialog* dia1=new dialog(this);
    dialog* dia2=new dialog(this);
    dialog* dia3=new dialog(this);
    dialog* dia4=new dialog(this);
    dia1->set_text(33,1);
    dia1->exec();
    dia2->set_text(34,1);
    dia2->exec();
    dia3->set_text(35,1);
    dia3->exec();
    dia4->set_text(36,1);
    dia4->exec();
    ui->pushButton_2->hide();
    ui->widget_4->hide();
    dialog* dia5=new dialog(this);
    dia5->set_text(37,1);
    dia5->exec();
    this->show();
    ui->widget_2->setGeometry(435,80,80,110);
    ui->widget_3->setGeometry(250,245,80,110);
    ui->widget_6->setGeometry(435,400,80,110);
    ui->widget->setGeometry(600,245,80,110);
    time->start(4000);
    postimer->start(40);
    ui->widget_7->show();
    grad_animation(ui->widget_7,1000,0.2,1);
}
void banished::set_pos(){
    ui->widget_2->setGeometry(435,ui->widget_2->y()+2,81,111);
    ui->widget_3->setGeometry(ui->widget_3->x()+2,245,81,111);
    ui->widget_6->setGeometry(435,ui->widget_6->y()-2,81,111);
    ui->widget->setGeometry(ui->widget->x()-2,245,81,111);
}
void banished::set()
{
    ui->widget_8->show();
    ui->pushButton_3->show();
    ui->widget_2->hide();
    ui->widget_3->hide();
    ui->widget_6->hide();
    ui->widget->hide();
    ui->widget_7->hide();
    time->stop();
}


void banished::on_pushButton_3_clicked()
{
    Oliver::audio->play(2);
    dialog* dia1=new dialog(this);
    dia1->set_text(38,1);
    dia1->exec();
    dialog* dia2=new dialog(this);
    dialog* enddia1=new dialog(this);
    dialog* enddia2=new dialog(this);
    if(Oliver::strong_level==2&&Oliver::courage_condition==1&&Oliver::skill_type==2&&Oliver::sword_type==2)
    {
        Oliver::metwithNPC[6]=1;
        dia2->set_text(39,1);
        enddia1->set_text(1,3);
        enddia2->set_text(2,3);
        dia2->exec();
        enddia1->exec();
        enddia2->exec();
    }
    else if(Oliver::skill_type==2&&Oliver::sword_type==2)
    {
        dia2->set_text(40,1);
        enddia1->set_text(3,3);
        enddia2->set_text(4,3);
        dia2->exec();
        enddia1->exec();
        enddia2->exec();
    }
    else
    {
        dia2->set_text(41,1);
        enddia1->set_text(5,3);
        dia2->exec();
        enddia1->exec();
    }
    end *happyend=new end(this);
    happyend->show();
}

