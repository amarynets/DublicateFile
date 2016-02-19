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
    QStringList takeResult();
private:
    QString hashFile(const QString& pathToFile) const;
    QVector<QPair<QString, QString>> result;
};

#endif // BUILDER_H
