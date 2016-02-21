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
    void createUnique(const QVector<QPair<QString, QString> > &input);
    void createDuplicateList(const QVector<QPair<QString, QString>> & input);
    QStringList takeResult();
private:
    bool pred(QPair<QString, QString> l, QPair<QString, QString> r)
    {
        int res = l.second.compare(r.second);
        return  res == 0;
    }

    QVector<QPair<QString, QString>> uniqueFiles;
    QVector<QPair<QString, QString>> duplicateFiles;
};

#endif // BUILDER_H
