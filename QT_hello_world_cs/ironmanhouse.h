#ifndef IRONMANHOUSE_H
#define IRONMANHOUSE_H

#include <QMainWindow>

namespace Ui {
class ironmanhouse;
}

class ironmanhouse : public QMainWindow
{
    Q_OBJECT

public:
    explicit ironmanhouse(QWidget *parent = nullptr);
    ~ironmanhouse();

private slots:
    void on_pushButton_clicked();

    void on_ironbutton_clicked();

    void on_fightiron_clicked();

private:
    Ui::ironmanhouse *ui;
};

#endif // IRONMANHOUSE_H
