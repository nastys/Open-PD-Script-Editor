#ifndef LIPSYNC_SETTINGS_H
#define LIPSYNC_SETTINGS_H

#include <QString>

struct lipsync_settings
{
    int engine;
    int format;
    int language;
    QString espeak_voice;
    int performer;
    bool delete_existing;
    int offset_before;
    int offset_after;
    bool close_mouth_p;
    bool close_mouth_b;
    bool close_mouth_n;
    bool close_mouth_m;
    bool close_mouth_end;
};

struct VSQX_Settings
{
    int track;
    int offset;
    int transition_duration;
    int transition_timeout;
    int performer;
    bool exclude_premeasure;
    bool delete_existing;
};

namespace lipsync_language
{
    const int ENGLISH_US=0;
    const int ENGLISH_RP=1;
    const int ITALIAN=2;
    const int SPANISH=3;
    const int SPANISH_LA=4;
    const int PORTUGUESE=5;
    const int PORTUGUESE_BR=6;
    const int FRENCH=7;
    const int FRENCH_BE=8;
    const int GERMAN=9;
    const int OTHER=10;
    const int LATINSCRIPT=11;
}

#endif // LIPSYNC_SETTINGS_H
