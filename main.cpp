#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"

int main(int argc, char *argv[])
{    
    QString path;
    if(argc == 2)
    {
        path = argv[1];
    }
    else
    {
        path = QDir::currentPath();
    }
    auto sl = Scaner::scanFolder(path);
    qDebug() << "Hi";
    return 0;
}
