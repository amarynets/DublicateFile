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
    //build.createUnique(input);
    //build.createDuplicateList(input);
    build.create(input);
    return build.takeResult();
}
