#ifndef ROLIG_VILLAGE_H
#define ROLIG_VILLAGE_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class rolig_village;
}

class rolig_village : public QMainWindow
{
    Q_OBJECT

public:
    QString context_name=":/map/rolig village/img/map/rolig village/rolig_village_main_map&NPC.png";
    static QString bgimg[5];
    explicit rolig_village(QWidget *parent = nullptr);
    void init();
    void bg_animation();
    int bg_pos;
    QTimer* bgtimer;

    ~rolig_village();

private slots:
    void on_gotosea_clicked();

    void on_ironmanhouse_clicked();

    void on_magichouse_clicked();

    void on_shop_clicked();

    void on_grandma_clicked();

    void on_crazyman_clicked();

private:
    Ui::rolig_village *ui;
};

#endif // ROLIG_VILLAGE_H
