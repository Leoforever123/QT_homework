#include "pass.h"
#include "ui_pass.h"
#include "dialog.h"
#include "getsword.h"
#include "oliver.h"


pass::pass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pass)
{

    ui->setupUi(this);
    connect(ui->button1,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("1");});
    connect(ui->button2,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("2");});
    connect(ui->button3,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("3");});
    connect(ui->button4,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("4");});
    connect(ui->button5,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("5");});
    connect(ui->button6,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("6");});
    connect(ui->button7,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("7");});
    connect(ui->button8,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("8");});
    connect(ui->button9,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("9");});
    connect(ui->button10,&QPushButton::clicked,[this](){Oliver::audio->play(2);onclick("0");});
    this->setWindowTitle("请输入密码");
}

void pass::onclick(QString str)
{
    QString past=ui->edit->text();
    past+=str;
    ui->edit->setText(past);
}
pass::~pass()
{
    delete ui;
}

void pass::on_clear_clicked()
{
    Oliver::audio->play(2);
    ui->edit->setText("");
}


void pass::on_yes_clicked()
{
    Oliver::audio->play(2);
    QString ans=ui->edit->text();
    if(ans=="13260119")
    {
        this->hide();
        dialog* dia=new dialog(this->parentWidget());
        dia->set_text(21,1);
        dia->exec();
        getsword* get=new getsword(this->parentWidget(),2);
        Oliver::sword_type=2;
        get->exec();
        delete this;
    }
    else
    {
        this->hide();
        dialog* dia=new dialog(this->parentWidget());
        dia->set_text(22,1);
        dia->exec();
        delete this;
    }
}

