
#ifndef OLIVER_H
#define OLIVER_H


#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include "status_show.h"
#include "effectaudio.h"


class Oliver : public QWidget
{
    Q_OBJECT
public:
    static int whethernew;
    static int pos;
    static int strong_level;       //强壮程度
    static int learn_ablity;       //学习能力
    static int sword_type;         //剑的类型
    static int skill_type;         //技能类型
    static int courage_condition;  //勇气
    static int metwithNPC[7];      //0.铁匠 1.女巫 2.商人 3.渔夫 4.奶奶 5.疯子 6.魔王
    static QString strong[3];
    static QString learn[2];
    static QString sword[3];
    static QString sword_img[3];
    static QString skill[3];
    static QString skill_img[3];
    static QString courage[2];
    static QString mapi[9];
    static effectaudio* audio;

    QPushButton* head;
    QPushButton* my_map;

    explicit Oliver(QWidget *parent = nullptr);

signals:

};

#endif // OLIVER_H
