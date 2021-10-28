#include "pdtime.h"

pdsplittime pdtime_split(int pdtime)
{
    // thanks to somewhatlurker

    pdsplittime temp;

    temp.frac = pdtime % 100000;
    pdtime -= temp.frac;
    pdtime /= 100000;

    temp.seconds = pdtime % 60;
    pdtime -= temp.seconds;
    pdtime /= 60;

    temp.minutes = pdtime % 60;
    pdtime -= temp.minutes;
    pdtime /= 60;

    temp.hours = pdtime;

    return temp;
}

QString pdtime_string(pdsplittime pdtime)
{
    QString strhours=QString::number(pdtime.hours, 10);
    while(strhours.length()<2) strhours.prepend('0');

    QString strminutes=QString::number(pdtime.minutes, 10);
    while(strminutes.length()<2) strminutes.prepend('0');

    QString strseconds=QString::number(pdtime.seconds, 10);
    while(strseconds.length()<2) strseconds.prepend('0');

    QString strfrac=QString::number(pdtime.frac, 10);
    while(strfrac.length()<5) strfrac.prepend('0');

    QString string = strhours+':'+strminutes+':'+strseconds+'.'+strfrac;

    return string;
}
