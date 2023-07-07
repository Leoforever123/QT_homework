#include "fire.h"
#include "ui_fire.h"
#include "oliver.h"
#include "set_context.h"
#include "dialog.h"
#include "pass.h"

fire::fire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fire)
{
    ui->setupUi(this);
    //初始化窗口参数
    this->setFixedSize(1024,576);
    this->setWindowTitle("OLIVER");
    //设置背景
    set_context(this,":/map/img/map/flammande dalen.jpg");
    //初始化主角
    Oliver* oliver=new Oliver(this);
    set_status(ui->statusbar,this);
    //初始化宝箱
    set_context(ui->box,":/button/img/box/box1.png");

}

fire::~fire()
{
    delete ui;
}

void fire::on_boxButton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    if(Oliver::sword_type==2)
    {
        dia->set_text(23,1);
        dia->exec();
        return;
    }
    dia->set_text(20,1);
    dia->exec();
    pass *pas=new pass(this);
    pas->exec();
}

