#include "processor.h"
#include "builder.h"

Processor::Processor()
{

}

Processor::~Processor()
{

}

QStringList Processor::process(QVector<QPair<QString, QString>> input)
{
    Builder build{};
    build.createUnique(input);
    build.createDuplicateList(input);

    return build.takeResult();
}
