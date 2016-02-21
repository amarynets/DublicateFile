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
    for(auto item : input)
    {
        build.addIfUnique(item);
    }
    build.createDuplicateList(input);

    return build.takeResult();
}
