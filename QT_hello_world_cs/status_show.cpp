#include "status_show.h"
#include "ui_status_show.h"
#include "oliver.h"
#include "set_context.h"

status_show::status_show(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::status_show)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setFixedSize(405,473);
    set_context(ui->oliver_img,":/character/img/character/braver.png");
    set_context(ui->sword_img,Oliver::sword_img[Oliver::sword_type]);
    set_context(ui->magicbook_img,Oliver::skill_img[Oliver::skill_type]);
    QString statu="";
    statu.append(Oliver::strong[Oliver::strong_level]);
    statu.append("、");
    statu.append(Oliver::learn[Oliver::learn_ablity]);
    statu.append("、");
    statu.append("\n");
    statu.append(Oliver::sword[Oliver::sword_type]);
    statu.append("、");
    statu.append("\n");
    statu.append(Oliver::skill[Oliver::skill_type]);
    statu.append("、");
    statu.append(Oliver::courage[Oliver::courage_condition]);
    statu.append("、");
    statu.append("\n");
    statu.append("正直的、善良的奥利弗");
    ui->status_label->setText(statu);
    ui->status_label->setFont(QFont("微软雅黑",22,10,0));
    set_context(this,":/button/img/button/muban.jpg");
    this->setWindowTitle("OLIVER");

}

status_show::~status_show()
{
    delete ui;
}

void status_show::on_toolButton_clicked()
{
    Oliver::audio->play(2);
    this->hide();
    delete this;
}

