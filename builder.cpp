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
            auto hashFileList = calculateHash(item);
            addIfNeeded(it, hashFileList);
        }
    }
}

QVector<FileHash> Builder::calculateHash(const QVector<QString> & input)
{
    QVector<FileHash> result;
    for(auto i : input)
    {
        auto hash = hash1MBFile(i);
        FileHash tmp;
        tmp.path = i;
        tmp.hash = hash;
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

void Builder::addIfNeeded(qint64 key, const QVector<FileHash> & input)
{
    for(auto i = 0; i < input.size() - 1; ++ i)
    {
        bool isHashEquals = input[i].hash == input[i+1].hash;
        bool isEquels = false;
        if(isHashEquals == true)
        {
            isEquels = isFileEquals(input[i], input[i+1]);
        }
        if(isEquels == true)
        {
            QVector<QString> tmp;
            tmp.push_back(input[i]);
            duplicateFileList[key] =
        }
    }
}

QStringList Builder::takeResult()
{

}
