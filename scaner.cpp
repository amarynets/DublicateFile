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
    QDirIterator it(folderName, QDirIterator::Subdirectories);
    QStringList files;
    while(it.hasNext())
    {
        if(it.fileName() != "." || it.fileName() != "..")
        {
            //qDebug() << it.filePath();
            files << it.filePath();
            it.next();
        }
        else
        {
            it.next();
        }
    }
    return files;
}

