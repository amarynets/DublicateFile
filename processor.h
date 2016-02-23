#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QStringList>

class Processor
{
public:
    static QStringList process(const QVector<QPair<QString, qint64>> & input);
};

#endif // PROCESSOR_H
