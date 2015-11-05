#include <QApplication>
#include <officepackagecontroller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* view = new MainWindow();

    OfficePackageModel* model = new OfficePackageModel();

    int length = 3;
    OfficePackage data[length];
    data[0] = OfficePackage("Office","Microsoft","4","870");
    data[1] = OfficePackage("SmartSute","Lotus","5","1020");
    data[2] = OfficePackage("Star Office","Sun","4","9");
    model->init(&data);



    view->setData(data, length);
    view->show();
    return a.exec();
}
