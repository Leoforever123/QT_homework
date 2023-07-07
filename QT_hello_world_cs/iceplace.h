#ifndef ICEPLACE_H
#define ICEPLACE_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class iceplace;
}

class iceplace : public QMainWindow
{
    Q_OBJECT

public:
    explicit iceplace(QWidget *parent = nullptr);
    ~iceplace();

private slots:
    void on_entericeberg_clicked();

private:
    Ui::iceplace *ui;
};

#endif // ICEPLACE_H
