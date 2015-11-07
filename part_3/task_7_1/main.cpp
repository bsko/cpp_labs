#include <QApplication>
#include <officepackagecontroller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow view; // view
    OfficePackageController controller; // controller
    OfficePackageModel model; // model
    int length = 3;
    OfficePackage data[length];
    data[0] = OfficePackage("Office","Microsoft","4","870");
    data[1] = OfficePackage("SmartSute","Lotus","5","1020");
    data[2] = OfficePackage("Star Office","Sun","4","9");
    view.setController(&controller);
    model.init(data, length);
    controller.init(&model, &view);

//    w.show();

    return a.exec();
}
