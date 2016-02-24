#include "processor.h"
#include "builder.h"

QStringList Processor::process(const QMap<qint64, QVector<QString> > &input)
{
    Builder build;
    build.createDuplicateList(input);
    return build.takeResult();
}
