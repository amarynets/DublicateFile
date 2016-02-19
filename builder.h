#ifndef BUILDER_H
#define BUILDER_H

#include <QStringList>

class Builder
{
public:
    Builder();
    ~Builder();
    void addIfNeadded(const QString& input);
    QStringList takeResult();
};

#endif // BUILDER_H
