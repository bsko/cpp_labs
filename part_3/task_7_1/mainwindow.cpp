#include "mainwindow.h"
#include <officepackagecontroller.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("№"));
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Наименование"));
    ui->tableWidget->setColumnWidth(2, 150);
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Производитель"));
    ui->tableWidget->setColumnWidth(3, 300);
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Количество составных частей"));
    ui->tableWidget->setColumnWidth(4, 150);
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Цена $"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QTableWidget* MainWindow::getDataTable() {
    return ui->tableWidget;
}

void MainWindow::on_pushButton_clicked()
{
    this->controller->handleRowAdd(this->ui->name->text(), this->ui->company->text(), this->ui->count->text(), this->ui->price->text());
    ui->update->setEnabled(false);
    ui->name->setText("");
    ui->company->setText("");
    ui->count->setText("");
    ui->price->setText("");
}

void MainWindow::setController(OfficePackageController *controller) {
    this->controller = controller;
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QModelIndexList list = ui->tableWidget->selectionModel()->selectedRows();
    int row = list.at(0).row();
    ui->name->setText(ui->tableWidget->item(row, 1)->text());
    ui->company->setText(ui->tableWidget->item(row, 2)->text());
    ui->count->setText(ui->tableWidget->item(row, 3)->text());
    ui->price->setText(ui->tableWidget->item(row, 4)->text());
    ui->update->setEnabled(true);
}

void MainWindow::on_update_clicked()
{
    QModelIndexList list = ui->tableWidget->selectionModel()->selectedRows();
    int row = list.at(0).row();
    this->controller->handleRowUpdate(row, ui->name->text(), ui->company->text(), ui->count->text(), ui->price->text());
    ui->update->setEnabled(false);
    ui->name->setText("");
    ui->company->setText("");
    ui->count->setText("");
    ui->price->setText("");
}
