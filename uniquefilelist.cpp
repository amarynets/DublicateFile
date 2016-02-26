#include "uniquefilelist.h"

QVector<FileHash> UniqueFileList::takeUniqueList(const QVector<FileHash> &input)
{
    QVector<FileHash> result;
    for(auto it : input)
    {
        auto pos = std::find_if(result.begin(), result.end(),[&it](const FileHash & rhs)
        {
            return it.hash == rhs.hash;
        });
        if(pos == result.end())
        {
            result.push_back(it);
        }
    }
    return result;
}

