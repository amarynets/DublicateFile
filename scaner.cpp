#include "scaner.h"

#include <QDirIterator>

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
