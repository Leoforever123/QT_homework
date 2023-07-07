#ifndef PASS_H
#define PASS_H

#include <QDialog>
#include <QString>

namespace Ui {
class pass;
}

class pass : public QDialog
{
    Q_OBJECT

public:
    explicit pass(QWidget *parent = nullptr);
    void onclick(QString str);
    ~pass();

private slots:
    void on_clear_clicked();

    void on_yes_clicked();

private:
    Ui::pass *ui;
};

#endif // PASS_H
