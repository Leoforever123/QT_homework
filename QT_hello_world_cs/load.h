#ifndef LOAD_H
#define LOAD_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT
signals:
    void full();
public:
    explicit load(QWidget *parent = nullptr);
    QTimer* time;
    void set_loadbar();
    void set_loadbar_text(int n);
    ~load();

private:
    Ui::load *ui;
};

#endif // LOAD_H
