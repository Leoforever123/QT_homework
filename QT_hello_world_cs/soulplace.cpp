#include "soulplace.h"
#include "ui_soulplace.h"
#include "set_context.h"
#include <QMessageBox>
#include "scene.h"
#include <QDebug>
#include "dialog.h"

soulplace::soulplace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::soulplace)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);

    //初始化窗口参数
    this->setFixedSize(1024,576);
    this->setWindowTitle("OLIVER");

    //设置背景
    set_context(this,":/map/img/map/Gullbyen.jpg");

    //初始化主角
    Oliver* oliver=new Oliver(this);
    set_status(ui->statusbar,this);

    connect(ui->actionenter,&QAction::triggered,this,[this](){
        if(Oliver::metwithNPC[6]!=1){
            QMessageBox::warning(this,"能力不足警告","大门紧闭着，但门上似乎有一个戒指形的印记");
            return;
        }
        else{
            scene *myscene= new scene(this);
            myscene->show();
        }
    });
}

soulplace::~soulplace()
{
    delete ui;
}

