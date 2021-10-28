#include "qstring_helper.h"

QString chopped(QString& string, int n)
{
    QString choppedstr = string;
    choppedstr.chop(n);
    return choppedstr;
}
