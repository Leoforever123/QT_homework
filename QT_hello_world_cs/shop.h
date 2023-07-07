#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>

namespace Ui {
class shop;
}

class shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();

private slots:
    void on_quit_clicked();

    void on_busbutton_clicked();

private:
    Ui::shop *ui;
};

#endif // SHOP_H
