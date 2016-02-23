#ifndef BUILDER_H
#define BUILDER_H

#include <QVector>
#include <QPair>
#include <QStringList>

class Builder
{
public:
    void createDuplicateList(const QVector<QPair<QString, qint64>>& input);
    QStringList takeResult();
private:
    QVector<QPair<QString, qint64>> dupList;
};

#endif // BUILDER_H
