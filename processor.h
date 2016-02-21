#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QStringList>

class Processor
{
public:
    Processor();
    ~Processor();
    QStringList process(QVector<QPair<QString, QString>> input);
};

#endif // PROCESSOR_H
