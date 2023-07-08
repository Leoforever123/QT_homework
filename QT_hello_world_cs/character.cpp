
#include "character.h"
#include "set_context.h"
#include <QDebug>

QString character::static_img[2]={":/animation/img/character/static-r.png",":/animation/img/character/static-l.png"};
QString character::run_img[2][4]={
    {
        ":/animation/img/character/run1-l.png",
        ":/animation/img/character/run2-l.png",
        ":/animation/img/character/run3-l.png",
        ":/animation/img/character/run2-l.png"
    },
    {
        ":/animation/img/character/run1-r.png",
        ":/animation/img/character/run2-r.png",
        ":/animation/img/character/run3-r.png",
        ":/animation/img/character/run2-r.png"
    }
};
QString character::sword_img[2][5]={
    {
        ":/animation/img/character/SWORD-R(1).png",
        ":/animation/img/character/SWORD-R(2).png",
        ":/animation/img/character/SWORD-R(3).png",
        ":/animation/img/character/SWORD-R(4).png",
        ":/animation/img/character/SWORD-R(5).png"
    },
    {
        ":/animation/img/character/SWORD-L(1).png",
        ":/animation/img/character/SWORD-L(2).png",
        ":/animation/img/character/SWORD-L(3).png",
        ":/animation/img/character/SWORD-L(4).png",
        ":/animation/img/character/SWORD-L(5).png"
    }
};

character::character(QWidget* parent):QWidget(parent)
{
    //状态参量初始化
    x=200;
    y=450;
    move_dx=0;
    move_dy=0;
    dir=1;
    v_y=0;
    v_x=3;
    a=0;
    run_action=0;
    sword_action=0;
    sword_judge=0;

    //窗口设置
    this->setFixedSize(80,100);
    this->setGeometry(200,450,80,100);
    set_context(this,static_img[0]);


    sword=new QWidget(this->parentWidget());
    sword->show();
    attacktimer=new QTimer(this);
    runtimer=new QTimer(this);

    //槽
    connect(runtimer,&QTimer::timeout,this,&character::run_animation);
    connect(attacktimer,&QTimer::timeout,this,&character::attack);

}
int character::dy(){
    if(isonboard()&&v_y<0)
    {
        a=0;
        v_y=0;
        //        qDebug()<<"isonboard";
        return 0;
    }
    if(isonboard()&&v_y>0)
    {
        a=1;
    }
    int dt=1;
    int dy=dt*(2*v_y-a*dt)/2;
    v_y-=a*dt;
    return dy;
}

bool character::isonboard(){
    return y==450;
}

void character::change_dir(int d){
    dir=d;
    switch(dir)
    {
    case 1:
        set_context(this,run_img[1][run_action]);
        break;
    case -1:
        set_context(this,run_img[0][run_action]);
        break;
    }
}

void character::move_R()
{
    if(!runtimer->isActive())
        runtimer->start(100);
    move_dx=v_x;
}

void character::move_L()
{
    if(!runtimer->isActive())
        runtimer->start(100);
    move_dx=-v_x;
}

void character::stop_move(){
    //    qDebug()<<"stop";
    if(dir==1)
        set_context(this,static_img[0]);
    if(dir==-1)
        set_context(this,static_img[1]);
    runtimer->stop();
    move_dx=0;
}

void character::jump(){
    if(isonboard())v_y=20;
}

void character::pos_refresh(){

    x=x+move_dx;
    move_dy=this->dy();
    y=y-move_dy;
    //    qDebug()<<y;
    if(x<0){
        //        qDebug()<<"x<0";
        x=0;
        if(y>0)this->setGeometry(0,y,80,100);
        else {
            this->setGeometry(0,0,80,100);
            y=0;
        }
    }
    else if(x>this->parentWidget()->width()-this->width()){
        x=this->parentWidget()->width()-this->width();
        if(y<this->parentWidget()->height()-this->height())
        {

            this->setGeometry(this->parentWidget()->width()-this->width(),y,80,100);
        }
        else {
            //            qDebug()<<"y ";
            this->setGeometry(this->parentWidget()->width()-this->width(),this->parentWidget()->height()-this->height(),80,100);
            y=this->parentWidget()->height()-this->height();
        }
    }
    else
        this->setGeometry(x,y,80,100);
}

void character::run_animation(){
    //    qDebug()<<dir;
    if(dir==-1)
        set_context(this,run_img[0][run_action]);
    if(dir==1)
        set_context(this,run_img[1][run_action]);

    run_action=(run_action+1)%4;
}

void character::attack(){
    sword->show();
    if(sword_judge==1){
        attacktimer->stop();
        sword_judge=0;
        sword->hide();
        return;
    }
    if(sword_action==4)
    {
        sword_judge=1;
    }
    switch(dir)
    {
    case 1:
        //    qDebug()<<"dir=1";
        sword->setGeometry(x-150,y-150,500,300);
        //    qDebug()<<sword->x();
        set_context(sword,sword_img[0][sword_action]);
        break;

    case -1:
        sword->setGeometry(x-270,y-150,500,300);
        set_context(sword,sword_img[1][sword_action]);
        break;
    }
    sword_action=(sword_action+1)%5;
}
