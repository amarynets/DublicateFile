//Призначений для порівняння 2 файлів

#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "filehash.h"

#include <QFile>
#include <QByteArray>

class Comparator
{
public:
    static bool isFilesEquals(const FileHash & file1, const FileHash & file2);
private:
    static bool binCompare(const FileHash & first, const FileHash & second);
};

#endif // COMPARATOR_H
