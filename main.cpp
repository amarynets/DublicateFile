#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"
#include "builder.h"

int main(int argc, char *argv[])
{    
    QString path = QDir::currentPath();
    Scaner scan;
    auto sl = scan.scanFolder(path);

    return 0;
}
