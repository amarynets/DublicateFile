#include "scaner.h"

#include <QDirIterator>


QVector<QPair<QString, qint64>> Scaner::scanFolder(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QVector<QPair<QString, qint64>> files;
    QPair<QString, qint64> tmp;
    while(it.hasNext())
    {
        it.next();
        tmp.first = it.filePath();
        auto info = it.fileInfo();
        tmp.second = info.size();
        files.push_back(tmp);
    }

    return files;
}

QMap<qint64, QVector<QString>> Scaner::scanFolder1(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QMap<qint64, QVector<QString>> files;
    QVector<QString> tmp;
    while(it.hasNext())
    {
        it.next();
        auto info = it.fileInfo();
        auto size = info.size();
        tmp.push_back(it.filePath());
        files[size] = tmp;
    }
    return files;
}
