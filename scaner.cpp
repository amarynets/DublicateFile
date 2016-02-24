#include "scaner.h"

#include <QDirIterator>

QMap<qint64, QVector<QString>> Scaner::scanFolder(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QMap<qint64, QVector<QString>> files;    
    while(it.hasNext())
    {
        it.next();
        auto info = it.fileInfo();
        auto size = info.size();
        bool isBe = files.contains(size);
        if(isBe == true)
        {
            auto val = files.value(size);
            //auto tmp = val.toVector();
            val.push_back(it.filePath());
            files[size] = val;
        }
        else
        {
            QVector<QString> elem;
            elem.push_back(it.filePath());
            files[size] = elem;
        }
    }
    return files;
}
