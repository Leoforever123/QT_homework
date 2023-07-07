#ifndef FIRE_H
#define FIRE_H

#include <QMainWindow>

namespace Ui {
class fire;
}

class fire : public QMainWindow
{
    Q_OBJECT

public:
    explicit fire(QWidget *parent = nullptr);
    ~fire();

private slots:
    void on_boxButton_clicked();

private:
    Ui::fire *ui;
};

#endif // FIRE_H
