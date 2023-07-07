#include <QWidget>
#include "effectaudio.h"
#include <QString>
#include <QDebug>

effectaudio::effectaudio(QObject *parent):QObject(parent)
{
    meffect=new QSoundEffect();
    thread=new QThread();
    meffect->moveToThread(thread);
    connect(this,&effectaudio::doplay,meffect,&QSoundEffect::play);
    connect(this,&effectaudio::dostop,meffect,&QSoundEffect::stop);
    thread->start();
}

effectaudio::~effectaudio()
{
    if(thread->isRunning())
    {
        thread->quit();
        thread->wait();
    }
}

void effectaudio::play(int type)
{
    if(meffect->isPlaying())
    {
        emit this->dostop();
        meffect->stop();
        return;
    }
    voice_type=type;
    QString wavname;
    switch(voice_type)
    {
    case VOICE_RUN:
        wavname="qrc:/wav/wav/running.wav";
        break;
    case VOICE_HOVER:
        wavname="qrc:/wav/wav/hover.wav";
        break;
    default:
        return;
    }
    meffect->setSource(QUrl(wavname));
    meffect->setVolume(0.3);
    //    qDebug()<<"start";
    emit this->doplay();

}
void effectaudio::set_loop(int n){
    if(n>=0)meffect->setLoopCount(n);
    else meffect->setLoopCount(QSoundEffect::Infinite);
}
void effectaudio::stop()
{
    emit this->dostop();
    //    qDebug()<<"stop";
}
void effectaudio::set_volume(double v){
    meffect->setVolume(v);
}
