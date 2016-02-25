#include "printer.h"

#include <QDebug>

void Printer::print(const QStringList & input)
{
    for(auto i : input)
    {
        qDebug() << i << endl;
    }
}

