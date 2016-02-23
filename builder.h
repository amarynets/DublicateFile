#ifndef BUILDER_H
#define BUILDER_H

#include <QVector>
#include <QMap>
#include <QPair>
#include <QStringList>

class Builder
{
public:
    void createDuplicateList(const QMap<qint64, QVector<QString>> & input);
    QStringList takeResult();
private:
    QVector<QPair<QString, QString>> calculateHash(QVector<QString>);
    QMap<qint64, QVector<QString>> dupList;
};

#endif // BUILDER_H
