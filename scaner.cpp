#include "scaner.h"

#include <QDirIterator>
#include <QDebug>

Scaner::Scaner()
{
}

Scaner::~Scaner()
{
}

QStringList Scaner::scanFolder(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QStringList files;
    while(it.hasNext())
    {
        it.next();
        files << it.filePath();
    }
    return files;
}

