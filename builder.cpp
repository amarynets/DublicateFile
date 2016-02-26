#include "builder.h"
#include "hash.h"
#include "uniquefilelist.h"

#include <QFile>
#include <QByteArray>
#include <QtAlgorithms>
#include <algorithm>
#include <QDebug>

void Builder::createDuplicateList(const QMap<qint64, QVector<QString> > & input)
{
    for(auto it : input.keys())
    {
        auto item = input.value(it);
        if(item.size() > 1)
        {
            auto hashFileList = Hash::calculateHash(item);
            addIfNeeded(it, hashFileList);
        }
    }
}

void Builder::addIfNeeded(qint64 key, const QVector<FileHash> & input)
{
    QVector<FileHash> uniqueFL = UniqueFileList::takeUniqueList(input);
    for(auto it : uniqueFL)
    {
        QVector<QString> dupList = compareFiles(it, input);
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
    QString newGroup("\n New group duplicate files");
    for(auto it : duplicateFileList.keys())
    {
        auto item = duplicateFileList.value(it);
        if(item.size() > 1)
        {
            result << newGroup;
            for(auto i : item)
            {
                result << i;
            }
        }
    }
    return result;
}

QVector<QString> Builder::compareFiles(const FileHash & file, const QVector<FileHash> & input)
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
    QVector<QString> tmp;
    for(auto i : result)
    {
        tmp.push_back(i.path);
    }
    return tmp;
}
