
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QMouseEvent>
#include "set_context.h"
#include "rolig_village.h"
#include "oliver.h"
#include "information.h"
#include "settings.h"
#include <QMediaPlayer>
#include <QtMultimedia>
#include <QAudioOutput>
#include "file.h"



int position=0;           //位置
QMediaPlayer* MainWindow::player=nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img_name[0]=":/map/mainwindow/img/map/mainwindow/dawn.jpg";
    img_name[1]=":/map/mainwindow/img/map/mainwindow/dusk.jpg";
    img_name[2]=":/map/mainwindow/img/map/mainwindow/evening.jpg";
    gamename=":/map/mainwindow/img/map/mainwindow/gamename.png";

    init_mainwindow();
    this->setWindowFlags(Qt::Window|Qt::WindowTitleHint);

    //创建子窗口
    rolig=new rolig_village();

    //设置音乐播放器
    if(player!=nullptr)
    {
        delete player;
    }
    player=new QMediaPlayer;
    QAudioOutput* audio=new QAudioOutput;
    player->setAudioOutput(audio);
    player->setSource(QUrl("qrc:/mp3/mp3/05 - Greenpath.mp3"));
    audio->setVolume(0.5);
    player->setLoops(-1);
    player->play();

    blacktimer= new QTimer(this);
    connect(blacktimer,&QTimer::timeout,this,&MainWindow::show_new_village);
}

void MainWindow::init_mainwindow()//用于初始化开始界面
{
    //获取时间
    QDateTime current_time = QDateTime::currentDateTime();
    QString StrCurrentTime = current_time.toString("hh");
    int hour=StrCurrentTime.toInt();

    //初始化窗口
    this->setWindowTitle("OLIVER");
    this->setFixedSize(1024,576);

    //初始化窗口背景
    img_choice=0;
    if(hour>=6&&hour<=16)img_choice=0;
    else if(hour>16&&hour<=19)img_choice=1;
    else img_choice=2;
    set_context(this,img_name[img_choice]);

    //初始化按钮位置
    ui->newgame->setGeometry(437,308,150,40);
    ui->continuegame->setGeometry(437,368,150,40);
    ui->settings->setGeometry(437,428,150,40);
    ui->exit->setGeometry(437,488,150,40);

    //显示游戏名称
    ui->gamename_widget->setGeometry(212,120,600,160);
    set_context(ui->gamename_widget,gamename);
    grad_animation(ui->gamename_widget,1000);
}

//用于更换开始界面背景
void MainWindow::img_change()
{
    img_choice++;
    img_choice=img_choice%3;
    set_context(this,img_name[img_choice]);
}

//用于检测开始界面的鼠标事件并更换背景图片
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    img_change();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_newgame_clicked()
{
    Oliver::audio->play(2);
    QWidget* black = new QWidget(this);
    black->setFixedSize(1024,576);
    black->show();
    set_context(black,":/icon/img/icon/black.png");
    blacktimer->start(2000);
    grad_animation(black,2000,0,1,1);

}
void MainWindow::show_new_village(){
    information* info=new information();
    this->hide();
    blacktimer->stop();
    QWidget* black = new QWidget(info);
    black->setFixedSize(1024,576);
    black->show();
    set_context(black,":/icon/img/icon/black.png");
    grad_animation(black,2000,1,0,1);
    info->show();
    connect(info,&information::conti,rolig,&QWidget::show);
}

void MainWindow::on_settings_clicked()
{
    Oliver::audio->play(2);
    settings *set=new settings(this);
    set->exec();
}


void MainWindow::on_exit_clicked()
{
    Oliver::audio->play(2);
    delete this;
}


void MainWindow::on_continuegame_clicked()
{
    Oliver::audio->play(2);
    init_by_file("data.txt");
    if(Oliver::whethernew==0)
    {
        information* info=new information();
        this->hide();
        rolig->show();
        info->show();
        Oliver::whethernew=1;
    }
    else
    {
        this->hide();
        rolig->show();
    }

}

