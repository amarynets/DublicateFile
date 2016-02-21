#ifndef BUILDER_H
#define BUILDER_H

#include <QStringList>
#include <QPair>
#include <QVector>

class Builder
{
public:
    Builder();
    ~Builder();
    void addIfUnique(const QPair<QString, QString> & input);
    void createDuplicateList(const QVector<QPair<QString, QString>> & input);
    QStringList takeResult();
private:
    QVector<QPair<QString, QString>> uniqueFiles;
    QVector<QPair<QString, QString>> duplicateFiles;
};

#endif // BUILDER_H
