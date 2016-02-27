#include "builder.h"
#include "hash.h"
#include "uniquefilelist.h"
#include "comparator.h"

#include <algorithm>

void Builder::createDuplicateList(const QMap<qint64, QVector<QString> > & input)
{
    for(auto it : input.keys())
    {
        auto item = input.value(it);
        if(item.size() > 1)
        {
            auto hashFileList = Hash::calculateHash(item);
            addIfNeeded(it, hashFileList);
        }
    }
}

//Добавлення файлу в список дуплікатів
void Builder::addIfNeeded(qint64 key, const QVector<FileHash> & input)
{
    QVector<FileHash> uniqueFL = UniqueFileList::takeUniqueList(input);
    for(auto it : uniqueFL)
    {
        QVector<QString> dupList = singleDuplicateList(it, input);
        if(dupList.size() > 1)
        {
            auto tmp = duplicateFileList.value(key);
            tmp += dupList;
            duplicateFileList[key] = tmp;
        }
    }
}



QStringList Builder::takeResult()
{
    QStringList result;
    QString newGroup("_________________________\n"
                     "New group duplicate files");
    for(auto it : duplicateFileList.keys())
    {
        auto item = duplicateFileList.value(it);
        if(item.size() > 1)
        {
            result << newGroup;
            for(auto i : item)
            {
                result << i;
            }
        }
    }
    return result;
}


//Створення списку дуплікатів файлу для файлів які рівні по розміру
QVector<QString> Builder::singleDuplicateList(const FileHash & file, const QVector<FileHash> & input)
{
    QVector<FileHash> result;
    for(auto i : input)
    {
        bool fileEquals = Comparator::isFilesEquals(file, i);
//Можлива некоректна робота, оскільки можуть додаватись по декілька файлів
        if(fileEquals == true)
        {
            auto pos = std::find_if(result.begin(), result.end(), [&file](const FileHash & rhs)
            {
                return file.path == rhs.path;
            });
            if(pos == result.end())
            {
                result.push_back(file);
                result.push_back(i);
            }
            else
            {
                result.push_back(i);
            }
        }
    }
    QVector<QString> tmp;
    for(auto i : result)
    {
        tmp.push_back(i.path);
    }
    return tmp;
}
