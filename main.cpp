#include "genpass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GenPass w;
    w.show();

    return a.exec();
}
