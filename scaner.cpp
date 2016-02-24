#include "scaner.h"

#include <QDirIterator>

QMap<qint64, QVector<QString>> Scaner::scanFolder(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QMap<qint64, QVector<QString>> files;    
    while(it.hasNext())
    {
        it.next();
        QFileInfo info = it.fileInfo();
        files[info.size()].append(it.filePath());
    }
    return files;
}
