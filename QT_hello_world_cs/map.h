#ifndef MAP_H
#define MAP_H

#include <QDialog>

namespace Ui {
class map;
}

class map : public QDialog
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    ~map();

private slots:
    void on_quit_clicked();

    void on_rolig_clicked();

    void on_iceplace_clicked();

    void on_fire_clicked();

    void on_banished_clicked();

private:
    Ui::map *ui;
};

#endif // MAP_H
