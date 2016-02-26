//Отримує QVector<FileHash>
//повертає список унікальних файлів
//унікальними вважаються файли з рівними хешами

#ifndef UNIQUEFILELIST_H
#define UNIQUEFILELIST_H

#include "filehash.h"

#include <QVector>

class UniqueFileList
{
public:
    static QVector<FileHash> takeUniqueList(const QVector<FileHash> &input);
};

#endif // UNIQUEFILELIST_H
