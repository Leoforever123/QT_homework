#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>

namespace Ui {
class information;
}

class information : public QWidget
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();

private slots:
    void on_pushButton_clicked();

private:
    Ui::information *ui;
};

#endif // INFORMATION_H
