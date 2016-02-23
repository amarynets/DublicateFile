#include "builder.h"

#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>

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

QVector<QPair<QString, QString>> Builder::calculateHash(const QVector<QString> & input)
{
    QVector<QPair<QString, QString>> result;
    for(auto i : input)
    {
        auto hash = hash1MBFile(i);
        QPair<QString, QString> tmp;
        tmp.first = i;
        tmp.second = hash;
        result.push_back(tmp);
    }
    return result;
}

QString Builder::hash1MBFile(const QString & filePath){
    QString result;
    QFile* file = new QFile(filePath);
    auto size = 1000 * 1000 + 24;
    if(file->open(QIODevice::ReadOnly) == true)
    {
        QByteArray fileData = file->read(size);
        QByteArray hashData = QCryptographicHash::hash(fileData, QCryptographicHash::Md5);
        result = hashData.toHex();
    }
    file->close();
    delete file;
    return result;
}

QStringList Builder::takeResult()
{

}
