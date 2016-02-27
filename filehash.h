#ifndef FILEHASH
#define FILEHASH

#include <QPair>
#include <QString>

struct FileHash
{
    FileHash(){}
    FileHash(QString pathFile, QString hashFile):
        path(pathFile), hash(hashFile)
    {}
    QString path;
    QString hash;
};

#endif // FILEHASH

