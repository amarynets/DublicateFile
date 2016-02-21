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
        bool equalsPath = it.first != dup->first;

        if(dup != input.end() && equalsPath == true)
        {
            duplicateFiles.push_back(it);
        }

        while(dup != input.end())
        {
            bool equalsHash = it.second == dup->second;
            equalsPath = it.first != dup->first;
            if(equalsPath == true && equalsHash == true)
            {
                duplicateFiles.push_back(*dup);
            }

            dup = qFind(dup, input.end(), it);
        }
    }
}

QStringList Builder::takeResult()
{
    qSort(duplicateFiles);
    QStringList result;
    for(auto it : duplicateFiles)
    {
        result << it.first;
    }
    return result;
}
