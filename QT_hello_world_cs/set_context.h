
#ifndef SET_CONTEXT_H
#define SET_CONTEXT_H
#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QLabel>
#include "oliver.h"
//用来设置窗口背景
inline void set_context(QWidget* ptr,QString filename)
{
    QPalette painter=(ptr->palette());
    QImage img=QImage(filename);
    img=img.scaled(ptr->size());
    QBrush *brush=new QBrush(img);
    painter.setBrush(QPalette::Window,*brush);
    ptr->setAutoFillBackground(true);
    ptr->setPalette(painter);
}
//动画效果
inline void grad_animation(QWidget* process,int time,double start=0,double end=1)
{
    QGraphicsOpacityEffect* widgetOpacity=new QGraphicsOpacityEffect(process);
    widgetOpacity->setOpacity(0);
    process->setGraphicsEffect(widgetOpacity);
    QPropertyAnimation* processopacity=new
        QPropertyAnimation(widgetOpacity,"opacity",process);
    processopacity->setDuration(time);
    processopacity->setStartValue(start);
    processopacity->setEndValue(end);
    processopacity->start(QAbstractAnimation::KeepWhenStopped);
}

//用于设置按钮背景
inline void set_button_context(QPushButton* btn,QWidget* parent,QString filename)
{
    QWidget* widget=new QWidget(parent);
    widget->setFixedSize(btn->size());
    widget->setGeometry(btn->geometry().x(),btn->geometry().y()+btn->geometry().height(),btn->geometry().width(),btn->geometry().height());
    set_context(widget,filename);
    widget->lower();
}


inline void set_status(QStatusBar* bar,QWidget* parent)
{
    QLabel* try1=new QLabel(QString("position:  ").append(Oliver::mapi[Oliver::pos]),parent);
    try1->setFont(QFont("微软雅黑",18,10,0));
    bar->setStyleSheet("background-color:rgb(255,142,85)");
    bar->addWidget(try1);
}
#endif // SET_CONTEXT_H
