
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rolig_village.h"
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    //窗口初始化
    MainWindow(QWidget *parent = nullptr);
    void init_mainwindow();
    ~MainWindow();

    //资源
    QString img_name[3];
    int img_choice;
    QString gamename;
    void img_change();

    //子窗口
    rolig_village* rolig;

    //bgm播放器
    static QMediaPlayer* player;

    //事件
    virtual void mousePressEvent(QMouseEvent* event);


private slots:
    void on_newgame_clicked();

    void on_settings_clicked();

    void on_exit_clicked();

    void on_continuegame_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
