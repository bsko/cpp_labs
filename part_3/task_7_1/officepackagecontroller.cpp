#include <officepackagecontroller.h>
#include <iostream>

void OfficePackageController::init(OfficePackageModel *model, MainWindow *view) {
    this->model = model;
    this->view = view;

    redraw();
    this->view->show();
}

OfficePackageController::~OfficePackageController() {
    this->model = 0;
    this->view = 0;
    delete this->model;
    delete this->view;
}

void OfficePackageController::redraw() {
    QVector<OfficePackage>* data = this->model->getData();
    this->view->getDataTable()->setRowCount(data->length());
    for(int i = 0; i < data->length(); i++) {
        if(this->view->getDataTable()->item(i, 0) == 0) {
            QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(i));
            item1->setFlags(Qt::ItemIsSelectable);
            this->view->getDataTable()->setItem(i , 0, item1);
            QTableWidgetItem* item2 = new QTableWidgetItem(data->at(i).name);
            item2->setFlags(Qt::ItemIsSelectable);
            this->view->getDataTable()->setItem(i , 1, item2);
            QTableWidgetItem* item3 = new QTableWidgetItem(data->at(i).company);
            item3->setFlags(Qt::ItemIsSelectable);
            this->view->getDataTable()->setItem(i , 2, item3);
            QTableWidgetItem* item4 = new QTableWidgetItem(data->at(i).count);
            item4->setFlags(Qt::ItemIsSelectable);
            this->view->getDataTable()->setItem(i , 3, item4);
            QTableWidgetItem* item5 = new QTableWidgetItem(data->at(i).price);
            item5->setFlags(Qt::ItemIsSelectable);
            this->view->getDataTable()->setItem(i , 4, item5);
        } else {
            this->view->getDataTable()->item(i , 1)->setText(data->at(i).name);
            this->view->getDataTable()->item(i , 2)->setText(data->at(i).company);
            this->view->getDataTable()->item(i , 3)->setText(data->at(i).count);
            this->view->getDataTable()->item(i , 4)->setText(data->at(i).price);
        }
    }
}

void OfficePackageController::handleRowUpdate(int row, QString name, QString company, QString count, QString price) {
    OfficePackage* package = new OfficePackage();
    package->name = name;
    package->company = company;
    package->count = count;
    package->price = price;
    (*this->model->getData())[row] = *package;
    redraw();
}

void OfficePackageController::handleRowAdd(QString name, QString company, QString count, QString price) {
    OfficePackage* item = new OfficePackage(name, company, count, price);
    this->model->getData()->push_back(*item);
    redraw();
}
