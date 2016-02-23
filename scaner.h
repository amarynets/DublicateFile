#ifndef SCANER_H
#define SCANER_H

#include <QVector>
#include <QPair>
#include <QMap>

class Scaner
{
public:
    static QMap<qint64, QVector<QString>> scanFolder(const QString & folderName);
};

#endif // SCANER_H
