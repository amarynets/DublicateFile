#include "comparator.h"

#include <QtAlgorithms>

bool Comparator::isFilesEquals(const FileHash & file1, const FileHash & file2)
{
    bool isPath = file1.path == file2.path;
    bool isHash = file1.hash == file2.hash;
    bool isEquals = false;
    if(isPath == false && isHash == true)
    {
        isEquals = binCompare(file1, file2);
    }
    return isEquals;
}

bool Comparator::binCompare(const FileHash & first, const FileHash & second)
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
