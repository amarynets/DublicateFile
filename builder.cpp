#include "builder.h"

#include <QtAlgorithms>
#include <algorithm>


Builder::Builder()
{
}

Builder::~Builder()
{
}

void Builder::createUnique(const QVector<QPair<QString, QString> > &input)
{
   std::copy(input.begin(), input.end(), uniqueFiles.begin());
   std::unique(uniqueFiles.begin(), uniqueFiles.end(), pred);
}

void Builder::createDuplicateList(const QVector<QPair<QString, QString> > &input)
{
    for(auto it : uniqueFiles)
    {
        auto dup = qFind(input, it);
        bool equalsPath = it.first != dup->first;
//якщо ми знайшли інший файл з іншим шляхом
        if(dup != input.end() && equalsPath == true)
        {
            duplicateFiles.push_back(it);
        }
// доки не переберемо весь список
        while(dup != input.end())
        {
            bool equalsHash = it.second == dup->second;
            equalsPath = it.first != dup->first;
            if(equalsPath == true && equalsHash == true)
            {
                duplicateFiles.push_back(*dup);
            }
// шукаєм наступний файл
            dup = qFind(dup + 1, input.end(), it);
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


