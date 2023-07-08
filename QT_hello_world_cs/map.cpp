#include "map.h"
#include "ui_map.h"
#include "set_context.h"
#include "load.h"
#include "rolig_village.h"
#include "iceplace.h"
#include <QMessageBox>
#include "dialogue.h"
#include "fire.h"
#include "banished.h"
#include "mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "soulplace.h"

map::map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setFixedSize(576,576);
    set_context(this,":/map/img/map/map.png");
    this->setWindowTitle("OLIVER");
}

map::~map()
{
    delete ui;
}

void map::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->hide();
    delete this;
}


void map::on_rolig_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::pos!=0&&Oliver::pos!=1&&Oliver::pos!=2&&Oliver::pos!=3&&Oliver::pos!=4)
    {
        Oliver::pos=0;
        rolig_village *rolig=new rolig_village;
        load* loadbar=new load();
        loadbar->set_loadbar_text(0);
        this->hide();
        loadbar->show();
        connect(loadbar,&load::full,[loadbar,this,rolig](){
            delete loadbar;
            rolig->show();
            delete this->parentWidget()->parentWidget();
        });
        return;
    }
    else
    {
        Oliver::pos=0;
        rolig_village *rolig=new rolig_village;
        rolig->show();
        delete this->parentWidget()->parentWidget();
    }

}


void map::on_iceplace_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::strong_level!=2)
    {
        QMessageBox::warning(this,"能力不足警告",dialogue::map_str[10]);
        return;
    }

    if(Oliver::pos!=5)
    {
        Oliver::pos=5;
        iceplace* ice=new iceplace();
        load* loadbar=new load();
        loadbar->set_loadbar_text(5);
        this->hide();
        loadbar->show();
        connect(loadbar,&load::full,[loadbar,this,ice](){
            delete loadbar;
            ice->show();
            delete this->parentWidget()->parentWidget();
        });
        return;
    }
    else
    {
        iceplace* ice=new iceplace();
        ice->show();
        delete this->parentWidget()->parentWidget();
    }
}


void map::on_fire_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::pos!=6)
    {
        Oliver::pos=6;
        fire* ice=new fire();
        load* loadbar=new load();
        loadbar->set_loadbar_text(6);
        this->hide();
        loadbar->show();
        connect(loadbar,&load::full,[loadbar,this,ice](){
            delete loadbar;
            ice->show();
            delete this->parentWidget()->parentWidget();
        });
        return;
    }
    else
    {
        fire* ice=new fire();
        ice->show();
        delete this->parentWidget()->parentWidget();
    }
}


void map::on_banished_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::pos!=7)
    {
        Oliver::pos=7;
        banished* ice=new banished();
        load* loadbar=new load();
        loadbar->set_loadbar_text(7);
        this->hide();
        loadbar->show();
        connect(loadbar,&load::full,[loadbar,this,ice](){
            delete loadbar;
            ice->show();
            delete this->parentWidget()->parentWidget();
        });
        return;
    }
    else
    {
        banished* ice=new banished();
        ice->show();
        delete this->parentWidget()->parentWidget();
    }
}


void map::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    if(Oliver::pos!=8)
    {
        Oliver::pos=8;
        soulplace* ice=new soulplace();
        load* loadbar=new load();
        loadbar->set_loadbar_text(8);
        this->hide();
        loadbar->show();
        connect(loadbar,&load::full,[loadbar,this,ice](){
            delete loadbar;
            ice->show();
            delete this->parentWidget()->parentWidget();
        });
        return;
    }
    else
    {
        soulplace* ice=new soulplace();
        ice->show();
        delete this->parentWidget()->parentWidget();
    }
}

