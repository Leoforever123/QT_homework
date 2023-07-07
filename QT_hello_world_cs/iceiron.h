#ifndef ICEIRON_H
#define ICEIRON_H

#include <QWidget>

namespace Ui {
class iceiron;
}

class iceiron : public QWidget
{
    Q_OBJECT

public:
    explicit iceiron(QWidget *parent = nullptr);
    ~iceiron();

private slots:
    void on_quit_clicked();

    void on_pushButton_clicked();

private:
    Ui::iceiron *ui;
};

#endif // ICEIRON_H
