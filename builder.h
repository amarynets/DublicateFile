#ifndef BUILDER_H
#define BUILDER_H

#include <QStringList>
#include <QVector>
#include <QPair>

class Builder
{
public:
    Builder();
    ~Builder();
    void addIfNeadded(const QString& input);
    QString hashFile(const QString& pathToFile) const;
    QStringList takeResult();
private:
    QVector<QPair<QString, QString>> result;
};

#endif // BUILDER_H
