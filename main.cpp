#include <QtGui/QApplication>
#include "MainWindow.h"


#include "DataStruct.h"
#include <fstream>

// include headers that implement a archive in simple text format
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
