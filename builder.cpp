#include "builder.h"

#include <QtAlgorithms>

Builder::Builder()
{
}

Builder::~Builder()
{
}

void Builder::addIfNeadded(const QPair<QString, QString> & input)
{
    auto it = qFind(uniqueFiles, input);
    if(it != uniqueFiles.end())
    {
        uniqueFiles.push_back(input);
    }
}
