#ifndef SCANER_H
#define SCANER_H

#include <QStringList>

class Scaner
{
public:
    Scaner();
    ~Scaner();

    QStringList scanFolder(const QString & folderName);
};

#endif // SCANER_H
