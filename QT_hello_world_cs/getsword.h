#ifndef GETSWORD_H
#define GETSWORD_H

#include <QDialog>

namespace Ui {
class getsword;
}

class getsword : public QDialog
{
    Q_OBJECT

public:
    explicit getsword(QWidget *parent = nullptr,int sword=1);
    ~getsword();

private slots:
    void on_quit_clicked();

private:
    Ui::getsword *ui;
};

#endif // GETSWORD_H
