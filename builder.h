//Клас Builder отримує список файлів та їх розміри.
//Створює список дуплікатів файлів
//Повертає результат у зручному форматі

#ifndef BUILDER_H
#define BUILDER_H

#include "filehash.h"

#include <QVector>
#include <QMap>
#include <QPair>
#include <QStringList>

class Builder
{
public:
    void createDuplicateList(const QMap<qint64, QVector<QString>> & input);
    QStringList takeResult();
private:
    void addIfNeeded(qint64 key, const QVector<FileHash> &input);
    bool isFileEquals(const FileHash & first, const FileHash & second);
    QVector<QString> singleDuplicateList(const FileHash & file, const QVector<FileHash> & input);

    QMap<qint64, QVector<QString>> duplicateFileList;
};

#endif // BUILDER_H
