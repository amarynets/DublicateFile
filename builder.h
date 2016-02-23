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

    QMap<qint64, QVector<QString>> dupList;
};

#endif // BUILDER_H
