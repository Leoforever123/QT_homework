
#ifndef CHARACTER_H
#define CHARACTER_H


#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QString>


class character:public QWidget
{
    Q_OBJECT

public:
    character(QWidget *parent = nullptr);
    //计时器
    QTimer* runtimer;
    QTimer* attacktimer;

    //状态参量
    int move_dx;
    int move_dy;
    int dir;
    int x,y;
    int v_x,v_y;
    int down_g;
    int up_g;
    int a;
    int run_action;
    int sword_action;
    bool isattacking;
    bool sword_judge;

    //特效
    QWidget* sword;
    void sword_animation();
    void run_animation();

    //状态判断函数
    bool isonboard();
    int dy();

    //动作函数
    void jump();
    void move_R();
    void move_L();
    void stop_move();
    void pos_refresh();
    void attack();

    //资源载入
    static QString static_img[2];
    static QString run_img[2][4];
    static QString sword_img[2][5];
    void change_dir(int d);


};

#endif // CHARACTER_H
