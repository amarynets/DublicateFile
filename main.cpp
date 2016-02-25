#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"
#include "processor.h"
#include "printer.h"

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
    qDebug() << "Scaning folder " << path << endl;
    auto fileList = Scaner::scanFolder(path);

    qDebug() << "Search duplicate files in folder " << path << endl;
    auto dupFileList = Processor::process(fileList);

    qDebug() << "Printing duplicate file from folder " << path << endl;
    Printer::print(dupFileList);

    return 0;
}
