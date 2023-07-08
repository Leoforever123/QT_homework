
#include "scene.h"
#include "ui_scene.h"
#include "set_context.h"
#include <QDebug>
#include "dialog.h"


scene::scene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scene)
{
    D_flag=false;
    A_flag=false;
    set_scene();
    ui->setupUi(this);
    timer=new QTimer(this);
    clicktimer=new QTimer(this);
    click_flag=1;
    timer->start(10);
    braver=new character(this);
    connect(timer,&QTimer::timeout,this,&scene::refresh);
    connect(clicktimer,&QTimer::timeout,this,&scene::change_click_flag);
    audio=new effectaudio(this);
    this->show();
    dialog* dia=new dialog(this);
    dia->set_text(3,2);
    dia->exec();
}

scene::~scene()
{
    delete ui;
}

void scene::set_scene(){
    this->setFixedSize(1024,576);
    set_context(this,":/map/img/map/bgimg.png");

}
void scene::refresh(){
    braver->pos_refresh();
    //    qDebug()<<braver->x<<' '<<braver->y;
}
void scene::keyPressEvent(QKeyEvent *ev){
    switch(ev->key())
    {
    case Qt::Key_A:
        if(ev->isAutoRepeat()&&!D_flag)
        {
            A_flag=true;
            braver->move_L();
        }
        else if(!A_flag&&!ev->isAutoRepeat()){
            braver->change_dir(-1);
            braver->move_L();
            //            qDebug()<<"haha";
            audio->set_loop(-1);
            audio->play(1);
            //            qDebug()<<"go";

            //            qDebug()<<"L";
            //            qDebug()<<braver->v_x;
            //            qDebug()<<braver->move_dx;
        }
        break;
    case Qt::Key_D:
        if(ev->isAutoRepeat()&&!D_flag)
        {
            D_flag=true;
            braver->move_R();
        }
        else if(!D_flag&&!ev->isAutoRepeat()){
            braver->change_dir(1);
            braver->move_R();
            //            qDebug()<<"haha";
            audio->set_loop(-1);
            audio->play(1);
            //            qDebug()<<"go";

            //            qDebug()<<"R";
        }
        break;
    case Qt::Key_Space:
        if(ev->isAutoRepeat()==false)
        {
            braver->jump();
            //            qDebug()<<"jump";
        }
    }
    QWidget::keyPressEvent(ev);
}
void scene::keyReleaseEvent(QKeyEvent *ev){
    switch(ev->key())
    {
    case Qt::Key_A:
        if(!ev->isAutoRepeat()){
            A_flag=false;
            if(braver->dir==-1)
            {
                braver->stop_move();
                //                audio->stop();
                //                qDebug()<<"really stop";
            }

        }
        break;
    case Qt::Key_D:
        if(!ev->isAutoRepeat()){
            D_flag=false;
            if(braver->dir==1)
            {
                braver->stop_move();
                audio->stop();
            }
            //            qDebug()<<"R_stop";
        }
        break;

    }
}
void scene::mousePressEvent(QMouseEvent *ev){
    if(ev->button()==Qt::LeftButton&&click_flag){
        //        qDebug()<<"click";
        click_flag=0;
        clicktimer->start(500);
        braver->attacktimer->start(20);
    }
}
void scene::change_click_flag(){
    click_flag=1;
    clicktimer->stop();
}

void scene::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
    delete this;
}

