#ifndef PDTIME_H
#define PDTIME_H

#include <QString>

struct pdsplittime
{
    int hours;
    int minutes;
    int seconds;
    int frac;
};

pdsplittime pdtime_split(int pdsplitpdtime);

QString pdtime_string(pdsplittime pdtime);

#endif // PDTIME_H
