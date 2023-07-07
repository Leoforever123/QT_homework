#include "outsea.h"
#include "ui_outsea.h"
#include "set_context.h"

outsea::outsea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::outsea)
{
    ui->setupUi(this);
    this->setFixedSize(405,473);
    set_context(this,":/map/rolig village/img/map/onthesea.png");
    set_context(ui->fish,":/character/img/character/fishman.png");
    this->setWindowTitle("OLIVER");


    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
}

outsea::~outsea()
{
    delete ui;
}

void outsea::on_quit_clicked()
{
    Oliver::audio->play(2);
    this->parentWidget()->show();
    this->hide();
    delete this;
}

