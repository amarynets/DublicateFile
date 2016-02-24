#include "builder.h"

#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>
#include <QtAlgorithms>
#include <algorithm>

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
    QVector<FileHash> uniqueFL = uniqueFileList(input);
    for(auto it : uniqueFL)
    {
        QVector<FileHash> dupList = compareFiles(it, input);
        if(dupList.size() > 1)
        {
            auto tmp = duplicateFileList.value(key);
            tmp += dupList;
            duplicateFileList[key] = tmp;
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

QVector<FileHash> Builder::uniqueFileList(const QVector<FileHash> &input)
{
    QVector<FileHash> result;
    for(auto it : input)
    {
        auto pos = std::find_if(result.begin(), result.end(),[&it](const FileHash & rhs)
        {
            return it.hash == rhs.hash;
        });
        if(pos == result.end())
        {
            result.push_back(it);
        }
    }
    return result;
}

QVector<FileHash> Builder::compareFiles(const FileHash & file, const QVector<FileHash> & input)
{
    QVector<FileHash> result;
    for(auto i : input)
    {
        bool isPath = file.path == i.path;
        bool isHash = file.hash == i.hash;
        bool isEquals = false;
        if(isPath == false && isHash == true)
        {
            isEquals = isFileEquals(file, i);
        }
//Можлива некоректна робота, оскільки можуть додаватись по декілька файлів
        if(isEquals == true)
        {
            auto pos = std::find_if(result.begin(), result.end(), [&file](const FileHash & rhs)
            {
                return file.path == rhs.path;
            });
            if(pos == result.end())
            {
                result.push_back(file);
                result.push_back(i);
            }
            else
            {
                result.push_back(i);
            }
        }
    }
    return result;
}
