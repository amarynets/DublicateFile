#include "scaner.h"

#include <QDirIterator>
#include <QDebug>
#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>

QVector<QPair<QString, qint64> > Scaner::scanFolder(const QString & folderName)
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
