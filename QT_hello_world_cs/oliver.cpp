
#include "oliver.h"
#include "set_context.h"
#include "status_show.h"
#include <QPushButton>
#include <QImage>
#include <QStatusBar>
#include <QMessageBox>
#include "map.h"

int Oliver::whethernew=0;
int Oliver::pos=0;
int Oliver::strong_level=0;       //强壮程度
int Oliver::learn_ablity=0;       //学习能力
int Oliver::sword_type=0;         //剑的类型
int Oliver::skill_type=0;         //技能类型
int Oliver::courage_condition=0;  //勇气
int Oliver::metwithNPC[7]={0,0,0,0,0,0,0};      //1.铁匠 2.女巫 3.商人 4.渔夫 5.奶奶 6.疯子
QString Oliver::strong[3]={"瘦弱的","健康的","健壮的"};
QString Oliver::learn[2]={"不太聪明的","聪明的"};
QString Oliver::sword[3]={"手无寸铁的","有一把长剑的","手握火焰剑的"};
QString Oliver::skill[3]={"不会魔法的","懂魔法的","精通魔法的"};
QString Oliver::courage[2]={"胆小的","勇敢的"};
QString Oliver::mapi[9]={
    "rolig village(若里村)",
    "rolig_sea(若里村海岸)",
    "铁匠铺",
    "魔法屋",
    "商店",
    "iskalde landet(极寒之地)",
    "flammande dalen(火焰谷)",
    "Banished(放逐之地)",
    "sjelens helligdom(灵魂圣地)"
};
QString Oliver::sword_img[3]={":/icon/img/icon/white.png",":/weapon&book/img/weapon&book/longsword.png",":/weapon&book/img/weapon&book/firesword.png"};
QString Oliver::skill_img[3]={":/icon/img/icon/white.png",":/weapon&book/img/weapon&book/magicbook1.png",":/weapon&book/img/weapon&book/magicbook2.png"};
effectaudio* Oliver::audio = new effectaudio();

Oliver::Oliver(QWidget *parent)
    : QWidget{parent}
{
    //设置人物图像和头像按钮
    switch (pos) {
    case 0:
        this->setGeometry(300,400,80,100);
        this->setFixedSize(80,100);
        break;
    case 1:
        this->setGeometry(850,360,80,100);
        this->setFixedSize(80,100);
        break;
    case 2:
        this->setGeometry(400,360,80,100);
        this->setFixedSize(80,100);
        break;
    case 3:
        this->setGeometry(350,280,80,100);
        this->setFixedSize(80,100);
        break;
    case 4:
        this->setGeometry(400,400,80,100);
        this->setFixedSize(80,100);
        break;
    case 5:
        this->setGeometry(850,360,80,100);
        this->setFixedSize(80,100);
        break;
    case 6:
        this->setGeometry(750,300,80,100);
        this->setFixedSize(80,100);
        break;
    case 7:
        this->setGeometry(800,360,80,100);
        this->setFixedSize(80,100);
        break;
    case 8:
        this->setGeometry(800,360,80,100);
        this->setFixedSize(80,100);
        break;
    default:
        break;
    }
    //设置头像按钮
    head=new QPushButton(parent);
    head->setGeometry(50,50,61,61);
    head->setIcon(QIcon(":/character/img/character/braver_head.png"));
    head->setIconSize(QSize(54,54));
    head->setStyleSheet("background-color:yellow");
    set_context(this,":/character/img/character/static-l.png");
    //设置地图按钮
    my_map=new QPushButton(parent);
    my_map->setGeometry(130,50,61,61);
    my_map->setText("地图");
    my_map->setFont(QFont("微软雅黑",11,10,0));
    my_map->setStyleSheet("QPushButton{color:yellow;background-color:brown}");

    connect(head,&QPushButton::clicked,this,[this](){
        Oliver::audio->play(2);
        status_show *status=new status_show(this);
        status->exec();
    });
    connect(my_map,&QPushButton::clicked,this,[this](){
        Oliver::audio->play(2);
        if(Oliver::pos!=7){
        map* show_map=new map(this);
        show_map->exec();
        }
        else{
        if(Oliver::metwithNPC[6]==0)
            QMessageBox::warning(this,"警告","你被黑暗力量控制了，暂时不能离开这里");
        else{
            map* show_map=new map(this);
            show_map->exec();
        }
        }
    });
}



