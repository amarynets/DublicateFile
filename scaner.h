#ifndef SCANER_H
#define SCANER_H

#include <QVector>
#include <QPair>

class Scaner
{
public:
    Scaner();
    ~Scaner();

    QVector<QPair<QString, QString>> scanFolder(const QString & folderName);
private:
    QString hashFile(const QString& pathToFile) const;
};

#endif // SCANER_H
