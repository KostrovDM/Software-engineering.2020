#include "mainwindow.h"
#include <QApplication>
//#include <mystyle.h>

int main(int argc, char *argv[])
{

//    QApplication::setStyle(new myStyle);
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
