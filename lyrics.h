#ifndef LYRICS_H
#define LYRICS_H

#include <QPlainTextEdit>

int getLyricLine(QStringList &lyrics, QString &lyric);
void fromVtt(QFile &file, QPlainTextEdit *plaintextedit, QPlainTextEdit *pvdb, int pvnum);

#endif // LYRICS_H
