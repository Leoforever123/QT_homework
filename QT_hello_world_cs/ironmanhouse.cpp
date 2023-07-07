#include "ironmanhouse.h"
#include "ui_ironmanhouse.h"
#include "set_context.h"
#include "getsword.h"
#include <QMessageBox>
#include "dialog.h"

ironmanhouse::ironmanhouse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ironmanhouse)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    //设置标题
    this->setWindowTitle("OLIVER");
    //设置背景
    this->setFixedSize(576,576);
    ui->ironman->setFixedSize(109,120);
    set_context(this,":/map/rolig village/img/map/rolig village/inside_iron_man's.jpg");
    set_context(ui->ironman,":/character/img/character/ironman.png");
    //初始化人物
    Oliver::pos=2;
    Oliver *oliver=new Oliver(this);
    //设置状态栏
    set_status(ui->statusbar,this);
}

ironmanhouse::~ironmanhouse()
{
    delete ui;
}

void ironmanhouse::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    this->parentWidget()->show();
    Oliver::pos=0;
    this->hide();
    delete this;
}


void ironmanhouse::on_ironbutton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    getsword* sword=new getsword(this);
    if(Oliver::sword_type!=2)
    Oliver::sword_type=1;
    if(Oliver::metwithNPC[0]==0)
    {
        dia->set_text(0,1);
        Oliver::metwithNPC[0]=1;
        dia->exec();
        sword->exec();
        return;
    }
    else
    {
        dia->set_text(1,1);
        dia->exec();
    }

}


void ironmanhouse::on_fightiron_clicked()
{
    Oliver::audio->play(2);
    QMessageBox::information(this,"恭喜！","你的身体得到了锻炼！");
    if(Oliver::strong_level!=2)
    Oliver::strong_level++;
}

