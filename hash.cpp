#include "hash.h"

#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>

QVector<FileHash> Hash::calculateHash(const QVector<QString> & input)
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

QString Hash::hash1MBFile(const QString & filePath){
    QString result;
    QFile file(filePath);
    int size = 1000 * 1000 + 24;
    if(file.open(QIODevice::ReadOnly) == true)
    {
        QByteArray fileData = file.read(size);
        QByteArray hashData = QCryptographicHash::hash(fileData, QCryptographicHash::Md5);
        result = hashData.toHex();
    }
    file.close();
    return result;
}
