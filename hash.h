//Клас Hash приймає список файлів
//рахує їхній хеш до 1 МБ
//якщо файл менший за 1 МБ - рахує хеш всього файлу

#ifndef HASH_H
#define HASH_H

#include "filehash.h"

#include <QVector>

class Hash
{
public:
    static QVector<FileHash> calculateHash(const QVector<QString> & input);
private:
    static QString hash1MBFile(const QString & filePath);
};

#endif // HASH_H
