#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QElapsedTimer>
#include <locale>

#include "scaner.h"
#include "processor.h"
#include "printer.h"

int main(int argc, char *argv[])
{    
    setlocale(LC_ALL, "Russian");
    QString path;
    if(argc == 2)
    {
        path = argv[1];
    }
    else
    {
        path = QDir::currentPath();
    }
    QElapsedTimer timer;
    timer.start();
    qDebug() << "Scaning folder " << path << endl;
    auto fileList = Scaner::scanFolder(path);

    qDebug() << "Search duplicate files in folder " << path << endl;
    auto dupFileList = Processor::process(fileList);

    qDebug() << "Printing duplicate file from folder " << path << endl;
    Printer::print(dupFileList);

    qDebug() << endl << "Program worked " << timer.elapsed() << " ms" << endl;
    return 0;
}
