#ifndef OFFICEPACKAGECONTROLLER
#define OFFICEPACKAGECONTROLLER

#endif // OFFICEPACKAGECONTROLLER

#include <mainwindow.h>
#include <officepackagemodel.h>

class OfficePackageController {
public:
    void init(OfficePackageModel* model, MainWindow* view);
    ~OfficePackageController();
    void handleRowUpdate(int row, QString name, QString company, QString count, QString price);
    void handleRowAdd(QString name, QString company, QString count, QString price);

private:
    MainWindow* view;
    OfficePackageModel* model;
    void redraw();
};
