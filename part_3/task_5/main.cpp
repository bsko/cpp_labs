#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int length = 3;
    OfficePackage data[length];
    data[0] = OfficePackage("Office","Microsoft","4","870");
    data[1] = OfficePackage("SmartSute","Lotus","5","1020");
    data[2] = OfficePackage("Star Office","Sun","4","9");
    w.setData(data, length);
    w.show();
    return a.exec();
}
