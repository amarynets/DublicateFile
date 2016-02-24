#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"
#include "processor.h"

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
    auto fileList = Scaner::scanFolder(path);
    auto dupFileList = Processor::process(fileList);
    qDebug() << "Hi";
    return 0;
}
