#include "settings.h"
#include "ui_settings.h"
#include "set_context.h"
#include "mainwindow.h"
#include <QAudioOutput>
#include <QDebug>

int settings::volume = 50;
settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    set_context(this,":/button/img/button/muban.jpg");
    ui->horizontalSlider->setValue(volume);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[this](int n){
        MainWindow::player->audioOutput()->setVolume(((float)n)/100);
        volume = n;
    });
    this->setWindowTitle("OLIVER");

}

settings::~settings()
{
    delete ui;
}
