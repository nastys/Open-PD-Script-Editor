#ifndef LIPSYNC_H
#define LIPSYNC_H

#include "lipsync_settings.h"
#include <QPlainTextEdit>

struct phoneme
{
    int time=0, mouthid=0;
};

struct lyric
{
    int starttime=0, endtime=0;
    QString lyric;
};

class LipSync_v1_0
{
public:
    static void lyricToPhoneme(QString &inLyric, QString &outPhonemes, QString &voice);
    static char phonemeToMouthId(QChar phoneme, lipsync_settings &settings);
    static void fillPhonemeList(QVector<lyric> &inLyrics, QVector<phoneme> &outPhonemes, lipsync_settings &settings);
    static void getLyrics(QFile &vtt, QVector<lyric> &lyrics, lipsync_settings &settings);
    static void lipsyncFromVtt(QTextEdit *dscpte, QFile &vtt, lipsync_settings &settings);

};

namespace mouthphonemes_v1_0
{
    const int mouth_ft_a=0;
    const int mouth_ft_i=10;
    const int mouth_ft_u=11;
    const int mouth_ft_e=1;
    const int mouth_ft_o=2;
    const int mouth_ft_m=8;
};

#endif // LIPSYNC_H
