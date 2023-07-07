#ifndef STATUS_SHOW_H
#define STATUS_SHOW_H

#include <QDialog>


namespace Ui {
class status_show;
}

class status_show : public QDialog
{
    Q_OBJECT

public:
    explicit status_show(QWidget *parent = nullptr);
    ~status_show();

private slots:
    void on_toolButton_clicked();

private:
    Ui::status_show *ui;
};

#endif // STATUS_SHOW_H
