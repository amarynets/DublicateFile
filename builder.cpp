#include "builder.h"

#include <QCryptographicHash>
#include <QFile>

void Builder::createDuplicateList(const QMap<qint64, QVector<QString> > & input)
{
    for(auto it : input.keys())
    {
        auto item = input.value(it);
        if(item.size() > 1)
        {
            auto hashList = calculateHash(item);
        }
    }
}

QVector<QPair<QString, QString>> Builder::calculateHash(QVector<QString>)
{
    QPair<QString, QString> result;

}

QStringList Builder::takeResult()
{

}
