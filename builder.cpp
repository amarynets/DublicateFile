#include "builder.h"

#include <QtAlgorithms>


Builder::Builder()
{
}

Builder::~Builder()
{
}

void Builder::addIfUnique(const QPair<QString, QString> & input)
{
    auto it = qFind(uniqueFiles, input);
    if(it != uniqueFiles.end())
    {
        uniqueFiles.push_back(input);
    }
}

void Builder::createDuplicateList(const QVector<QPair<QString, QString> > &input)
{
    for(auto it : uniqueFiles)
    {
        auto dup = qFind(input, it);
        while(dup != input.end())
        {
            bool equalsHash = it.second == dup->second;
            bool equalsPath = it.first != dup->first;
            if(equalsPath == true && equalsHash == true)
            {
                duplicateFiles.push_back(*dup);
            }
        }
    }
}

QStringList Builder::takeResult()
{
    qSort(duplicateFiles);

}
