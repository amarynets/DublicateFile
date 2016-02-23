#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QStringList>

class Processor
{
public:
    static QStringList process(const QMap<qint64, QVector<QString>> & input);
};

#endif // PROCESSOR_H
