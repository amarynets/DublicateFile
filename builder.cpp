#include "builder.h"

#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>

Builder::Builder()
{
}

Builder::~Builder()
{
}

void Builder::addIfNeadded(const QString& input)
{
}

QString Builder::hashFile(const QString& pathToFile) const
{
    QFile file(pathToFile);
    QString result;
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash * hash;
        QByteArray tmp = hash->hash(file.readAll(), QCryptographicHash::Md5);
        file.close();
         result = QString(tmp.toHex());
    }
    return result;
}
