#include "dialog.h"
#include "ui_dialog.h"
#include "set_context.h"
#include "dialogue.h"
#include <QPoint>

int dialog::maxlen = 50;
dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    //窗口设置
    set_context(this,":/button/img/button/muban.jpg");
    this->setWindowTitle("Dialogue");
    this->setFixedSize(this->parentWidget()->width(),200);
    ui->continue_2->setGeometry(this->parentWidget()->width()-75,150,60,30);
    ui->continue_2->hide();
    ui->quit->setGeometry(this->parentWidget()->width()-75,10,51,51);
    ui->dia->setGeometry(0,0,this->parentWidget()->width()-100,200);
    maxlen = (this->parentWidget()->width()-100)/19;
    ui->dia->setText("");
    //位置设置
    QPoint point = this->parentWidget()->mapToGlobal(QPoint(0,0));
    this->setGeometry(point.x(),point.y()+376,1024,400);
    //计时器初始化
    diatimer = new QTimer(this);
    connect(diatimer,&QTimer::timeout,this,&dialog::show_act);

}

void dialog::set_text(int n,int type) {
    switch(type){
    case 1:
        di = dialogue::map_str[n];
        break;
    case 2:
        di = dialogue::other_str[n];
        break;
    case 3:
        di = dialogue::end_str[n];
        break;
    }
    pos = 0;
    judge = 0;
    roll_sum=0;
    diatimer->start(20);
}
void dialog::show_act(){
    if(pos==di.length()){
        diatimer->stop();
        ui->continue_2->hide();
        return;
    }

    if(judge==maxlen){
        ui->dia->setText(ui->dia->text()+'\n');
        roll_sum++;
        judge=0;
    }
    if(roll_sum>=6){
        diatimer->stop();
        ui->continue_2->show();
        roll_sum = 0;
        return;
    }

    ui->dia->setText(ui->dia->text()+di[pos]);

    judge++;
    if(di[pos]=='\n'){
        judge=0;
        roll_sum++;
    }
    pos++;
}
dialog::~dialog()
{
    delete ui;
}

void dialog::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->hide();
    this->parentWidget()->show();
    delete this;
}


void dialog::on_continue_2_clicked()
{
    Oliver::audio->play(2);
    ui->dia->setText("");
    diatimer->start(20);
    judge=0;
    ui->continue_2->hide();
}

