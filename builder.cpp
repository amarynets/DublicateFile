#include "builder.h"

void Builder::createDuplicateList(const QMap<qint64, QVector<QString> > & input)
{
    for(auto it : input.keys())
    {
        auto item = input.value(it);
        if(item.size() > 1)
        {

        }
    }
}

QStringList Builder::takeResult()
{

}
