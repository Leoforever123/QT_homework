#include "information.h"
#include "ui_information.h"
#include "set_context.h"

information::information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
    set_context(this,":/map/mainwindow/img/map/fog.jpg");
    this->setWindowTitle("OLIVER");
}

information::~information()
{
    delete ui;
}

void information::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    delete this;
}

