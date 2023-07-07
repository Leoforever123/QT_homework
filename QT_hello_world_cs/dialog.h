#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QTimer>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    static int maxlen;
    QTimer *diatimer;
    QString di;
    int pos;
    int judge;
    int roll_sum;

    void set_dia_text_map(int n);
    void set_dia_text_other(int n);
    void set_dia_text_end(int n);
    void set_text(int n,int type);
    void show_act();
    ~dialog();

private slots:
    void on_quit_clicked();

    void on_continue_2_clicked();

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
