#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, 220);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Наименование"));
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Производитель"));
    ui->tableWidget->setColumnWidth(2, 300);
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Количество составных частей"));
    ui->tableWidget->setColumnWidth(3, 150);
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Цена $"));
}

void MainWindow::setData(OfficePackage data[], int length) {
    ui->tableWidget->setRowCount(length);
    for(int i = 0; i < length; i++) {
        QTableWidgetItem* item1 = new QTableWidgetItem(data[i].name);
        ui->tableWidget->setItem(i , 0, item1);
        QTableWidgetItem* item2 = new QTableWidgetItem(data[i].company);
        ui->tableWidget->setItem(i , 1, item2);
        QTableWidgetItem* item3 = new QTableWidgetItem(data[i].count);
        ui->tableWidget->setItem(i , 2, item3);
        QTableWidgetItem* item4 = new QTableWidgetItem(data[i].price);
        ui->tableWidget->setItem(i , 3, item4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int count = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(count);
    QTableWidgetItem* item1 = new QTableWidgetItem(ui->name->text());
    ui->tableWidget->setItem(count , 0, item1);
    QTableWidgetItem* item2 = new QTableWidgetItem(ui->company->text());
    ui->tableWidget->setItem(count , 1, item2);
    QTableWidgetItem* item3 = new QTableWidgetItem(ui->count->text());
    ui->tableWidget->setItem(count , 2, item3);
    QTableWidgetItem* item4 = new QTableWidgetItem(ui->price->text());
    ui->tableWidget->setItem(count , 3, item4);

    ui->name->setText("");
    ui->company->setText("");
    ui->count->setText("");
    ui->price->setText("");
}
