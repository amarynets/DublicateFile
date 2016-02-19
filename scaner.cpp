#include "scaner.h"

#include <QDirIterator>
#include <QDebug>
#include <QCryptographicHash>
#include <QFile>
#include <QByteArray>

Scaner::Scaner()
{
}

Scaner::~Scaner()
{
}

QVector<QPair<QString, QString>> Scaner::scanFolder(const QString & folderName)
{
    QDirIterator it(folderName, QDir::Files|QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    QVector<QPair<QString, QString>> files;
    QPair<QString, QString> tmp;
    while(it.hasNext())
    {
        it.next();
        tmp.first = it.filePath();
        tmp.second = hashFile(it.filePath());
        files.push_back(tmp);
    }
    return files;
}

QString Scaner::hashFile(const QString& pathToFile) const
{
    QFile file(pathToFile);
    QString result;
    if(file.open(QIODevice::ReadOnly))
    {
        QCryptographicHash * hash;
        QByteArray tmp = hash->hash(file.readAll(), QCryptographicHash::Md5);
        file.close();
         result = QString(tmp.toHex());
    }
    return result;
}
