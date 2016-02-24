#include "builder.h"

#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>
#include <QtAlgorithms>
#include <algorithm>

bool pred(const QString & l, const QString & r)
{
    return l == r;
}

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

void Builder::addIfNeeded(qint64 key, const QVector<FileHash> & input)
{
    for(auto i : input)
    {
        for(auto j : input)
        {
            bool isPath = i.path == j.path;
            bool isHash = i.hash == j.hash;
            bool isEquals = false;
            if(isPath == false && isHash == true)
            {
               isEquals = isFileEquals(i, j);
            }
            if(isEquals == true)
            {
               auto vecResult = duplicateFileList.value(key);
               vecResult.push_back(i.path);
               std::unique(vecResult.begin(), vecResult.end(), pred);
               duplicateFileList[key] = vecResult;
            }
        }
    }
}

bool Builder::isFileEquals(const FileHash & first, const FileHash & second)
{
    QFile f1(first.path);
    QFile f2(second.path);
    bool isOpen1 = f1.open(QIODevice::ReadOnly);
    bool isOpen2 = f2.open(QIODevice::ReadOnly);
    bool result = false;
    if(isOpen1 == true && isOpen2 == true)
    {
        QByteArray data1 = f1.readAll();
        QByteArray data2 = f2.readAll();
        result = qEqual(data1.begin(), data1.end(), data2.begin());
    }
    return result;
}

QStringList Builder::takeResult()
{
    QStringList result;
    for(auto it : duplicateFileList.keys())
    {
        auto item = duplicateFileList.value(it);
        if(item.size() > 1)
        {
            for(auto i : item)
            {
                result << i;
            }
        }
    }
    return result;
}
