
#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QTimer>
#include "character.h"
#include <QMouseEvent>
#include "effectaudio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class scene; }
QT_END_NAMESPACE

class scene : public QWidget

{
    Q_OBJECT

public:
    scene(QWidget *parent = nullptr);
    ~scene();
    void refresh();
    QTimer* timer;
    QTimer* clicktimer;
    character* braver;
    void set_scene();
    void change_click_flag();
    effectaudio* audio;

    //按键控制
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void keyReleaseEvent(QKeyEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    bool D_flag;
    bool A_flag;
    bool space_flag;
    bool click_flag;

private slots:
    void on_pushButton_clicked();

private:
    Ui::scene *ui;
};

#endif // SCENE_H
