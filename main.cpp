#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "scaner.h"
#include "builder.h"

int main(int argc, char *argv[])
{    
    QString path = QDir::currentPath();
    Scaner scan;
    QStringList sl = scan.scanFolder(path);

    Builder b;
    auto res = b.hashFile(sl[0]);

    return 0;
}
