#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"
#include "processor.h"

int main(int argc, char *argv[])
{    
    //QString path = QDir::currentPath();
    QString path = "F:/Project/DublicateFile/test";
    Scaner scan;
    auto sl = scan.scanFolder(path);
    Processor proc;
    auto result = proc.process(sl);
    return 0;
}
