#ifndef ROLIG_SEA_H
#define ROLIG_SEA_H

#include <QMainWindow>
#include <QTimer>


namespace Ui {
class rolig_sea;
}

class rolig_sea : public QMainWindow
{
    Q_OBJECT

public:
    explicit rolig_sea(QWidget *parent = nullptr);
    int sea;
    QTimer* seatimer;
    static QString seaimg[4];
    ~rolig_sea();

private slots:
    void on_back_clicked();


    void on_pushButton_clicked();
    void sea_change();

private:
    Ui::rolig_sea *ui;
};

#endif // ROLIG_SEA_H
