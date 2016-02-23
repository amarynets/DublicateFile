#ifndef SCANER_H
#define SCANER_H

#include <QVector>
#include <QPair>

class Scaner
{
public:
    static QVector<QPair<QString, qint64>> scanFolder(const QString & folderName);
};

#endif // SCANER_H
