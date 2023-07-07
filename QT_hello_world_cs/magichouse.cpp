#include "magichouse.h"
#include "ui_magichouse.h"
#include "set_context.h"
#include "getmagic.h"
#include "dialog.h"


magichouse::magichouse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::magichouse)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    //设置标题
    this->setWindowTitle("OLIVER");
    //设置背景
    this->setFixedSize(576,576);
    ui->magicwomen->setFixedSize(150,150);
    set_context(this,":/map/rolig village/img/map/rolig village/inside_magichouse.jpg");
    set_context(ui->magicwomen,":/character/img/character/magicwoman.png");
    //初始化人物
    Oliver::pos=3;
    Oliver *oliver=new Oliver(this);
    //设置状态栏
    set_status(ui->statusbar,this);
}

magichouse::~magichouse()
{
    delete ui;
}

void magichouse::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->parentWidget()->show();
    this->hide();
    Oliver::pos=0;
    delete this;
}


void magichouse::on_magicbutton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    Oliver::skill_type=1;
    Oliver::learn_ablity=1;
    if(Oliver::metwithNPC[1]==0)
    {
        getmagic*magic =new getmagic(this);
        dia->set_text(2,1);
        Oliver::metwithNPC[1]=1;
        dia->exec();
        magic->exec();
        return;
    }
    else
    {
        dia->set_text(3,1);
        dia->exec();
    }

}

