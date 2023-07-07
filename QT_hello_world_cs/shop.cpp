#include "shop.h"
#include "ui_shop.h"
#include "set_context.h"
#include "dialog.h"

shop::shop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    //设置标题
    this->setWindowTitle("OLIVER");
    //设置背景
    this->setFixedSize(576,576);
    ui->businessman->setFixedSize(150,150);
    set_context(this,":/map/rolig village/img/map/rolig village/inside_shop.jpg");
    set_context(ui->businessman,":/character/img/character/businessman.png");
    //初始化人物
    Oliver::pos=4;
    Oliver *oliver=new Oliver(this);
    //设置状态栏
    set_status(ui->statusbar,this);
}

shop::~shop()
{
    delete ui;
}

void shop::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->parentWidget()->show();
    this->hide();
    Oliver::pos=0;
    delete this;
}


void shop::on_busbutton_clicked()
{
    Oliver::audio->play(2);
    dialog* dia=new dialog(this);
    dia->set_text(4,1);
    dia->exec();
}

