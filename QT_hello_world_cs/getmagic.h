#ifndef GETMAGIC_H
#define GETMAGIC_H

#include <QDialog>

namespace Ui {
class getmagic;
}

class getmagic : public QDialog
{
    Q_OBJECT

public:
    explicit getmagic(QWidget *parent = nullptr);
    ~getmagic();

private slots:
    void on_toolButton_clicked();

private:
    Ui::getmagic *ui;
};

#endif // GETMAGIC_H
