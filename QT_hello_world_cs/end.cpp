#include "end.h"
#include "ui_end.h"
#include "mainwindow.h"
#include "oliver.h"
#include "set_context.h"

end::end(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
    set_context(this,":/character/img/character/authors.png");
    MainWindow::player->stop();
    MainWindow::player->setSource(QUrl("qrc:/mp3/mp3/end.mp3"));
    MainWindow::player->play();
    this->setWindowTitle("end");
}

end::~end()
{
    delete ui;
}

void end::on_pushButton_clicked()
{
    Oliver::audio->play(2);
    MainWindow::player->stop();
    Oliver::pos=0;
    MainWindow *window=new MainWindow;


    window->show();
    delete this->parentWidget();


}

