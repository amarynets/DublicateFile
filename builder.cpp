#include "builder.h"

#include <QtAlgorithms>
#include <QSet>


Builder::Builder()
{
}

Builder::~Builder()
{
}

void Builder::createUnique(const QVector<QPair<QString, QString> > &input)
{
//    uniqueFiles.push_back(input[0]);
//    for(auto i : input)
//    {
//        auto find = qFind(uniqueFiles, i);
//        if(find != uniqueFiles.end())
//        {
//            continue;
//        }
//        else
//        {
//            uniqueFiles.push_back(i);
//        }
//    }
    auto list = input.toList();
    QSet<QPair<QString, QString> > set = list.toSet();
    for(auto i : set)
    {
        uniqueFiles.push_back(i);
    }
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
