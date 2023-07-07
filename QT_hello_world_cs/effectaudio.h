
#ifndef EFFECTAUDIO_H
#define EFFECTAUDIO_H

#include <QThread>
#include <QSoundEffect>
#include <QObject>

enum VOICE_TYPE{
    VOICE_SWORD,
    VOICE_RUN,
    VOICE_HOVER
};

class effectaudio:public QObject
{
    Q_OBJECT
public:
    effectaudio(QObject* parent=nullptr);
    ~effectaudio();
signals:
    void doplay();
    void dostop();

public slots:
    void play(int type=0);
    void stop();
    void set_loop(int);
    void set_volume(double);
private:
    int voice_type;
    QSoundEffect* meffect;
    QThread* thread;
};

#endif // EFFECTAUDIO_H
