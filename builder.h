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
    QVector<FileHash> calculateHash(const QVector<QString> & input);
    QString hash1MBFile(const QString & filePath);
    void addIfNeeded(qint64 key, const QVector<FileHash> &input);
    bool isFileEquals(const FileHash & first, const FileHash & second);

    QMap<qint64, QVector<QString>> duplicateFileList;
};

#endif // BUILDER_H
