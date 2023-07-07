#ifndef MAGICHOUSE_H
#define MAGICHOUSE_H

#include <QMainWindow>

namespace Ui {
class magichouse;
}

class magichouse : public QMainWindow
{
    Q_OBJECT

public:
    explicit magichouse(QWidget *parent = nullptr);
    ~magichouse();

private slots:
    void on_quit_clicked();

    void on_magicbutton_clicked();

private:
    Ui::magichouse *ui;
};

#endif // MAGICHOUSE_H
