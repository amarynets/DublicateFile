#include "scaner.h"

#include <QDir>

Scaner::Scaner()
{
}

Scaner::~Scaner()
{
}

QStringList Scaner::scanFolder(const QString & folderName)
{
    QDir dir(folderName);

    QStringList files = dir.entryList(QDir::Files);
    QStringList::iterator it;
    QStringList dirs = dir.entryList(QDir::Dirs);
    it = dirs.begin();
    while(it != dirs.end())
    {
        if(*it != "." && *it != "..")
        {
            scanFolder(folderName + "/" + *it);
        }
        else
        {
            ++it;
        }
    }
    return files;
}

