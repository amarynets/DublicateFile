#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"

int main(int argc, char *argv[])
{    
    QString path = QDir::currentPath();
    Scaner scan;
    QStringList sl = scan.scanFolder(path);


    for(auto i : sl)
    {
         qDebug() << i;
    }

    return 0;
}
