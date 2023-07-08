#ifndef SOULPLACE_H
#define SOULPLACE_H

#include <QMainWindow>

namespace Ui {
class soulplace;
}

class soulplace : public QMainWindow
{
    Q_OBJECT

public:
    explicit soulplace(QWidget *parent = nullptr);
    ~soulplace();

private slots:

private:
    Ui::soulplace *ui;
};

#endif // SOULPLACE_H
