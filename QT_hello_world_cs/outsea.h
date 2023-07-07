#ifndef OUTSEA_H
#define OUTSEA_H

#include <QDialog>

namespace Ui {
class outsea;
}

class outsea : public QDialog
{
    Q_OBJECT

public:
    explicit outsea(QWidget *parent = nullptr);
    ~outsea();

private slots:
    void on_quit_clicked();

private:
    Ui::outsea *ui;
};

#endif // OUTSEA_H
