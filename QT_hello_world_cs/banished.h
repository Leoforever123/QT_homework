#ifndef BANISHED_H
#define BANISHED_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class banished;
}

class banished : public QMainWindow
{
    Q_OBJECT

public:
    explicit banished(QWidget *parent = nullptr);
    QTimer *time;
    QTimer *postimer;
    void set();
    void set_pos();
    ~banished();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::banished *ui;
};

#endif // BANISHED_H
