
#ifndef FILE_H
#define FILE_H
#include "oliver.h"
#include <QFile>
#include <QString>

inline void setfile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QFile::Truncate);
    QDataStream fout(&file);
    fout<<Oliver::whethernew;
    fout<<Oliver::courage_condition<<Oliver::learn_ablity<<Oliver::skill_type<<Oliver::sword_type<<Oliver::strong_level;
    fout<<Oliver::metwithNPC[0]<<Oliver::metwithNPC[1]<<Oliver::metwithNPC[2]<<Oliver::metwithNPC[3]<<Oliver::metwithNPC[4]<<Oliver::metwithNPC[5]<<Oliver::metwithNPC[6];
    file.close();

}
inline void init_by_file(QString filename)
{
    Oliver::pos=0;
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QDataStream fin(&file);
    fin>>Oliver::whethernew;
    fin>>Oliver::courage_condition>>Oliver::learn_ablity>>Oliver::skill_type>>Oliver::sword_type>>Oliver::strong_level;
    fin>>Oliver::metwithNPC[0]>>Oliver::metwithNPC[1]>>Oliver::metwithNPC[2]>>Oliver::metwithNPC[3]>>Oliver::metwithNPC[4]>>Oliver::metwithNPC[5]>>Oliver::metwithNPC[6];
    file.close();
}

#endif //FILE_H
