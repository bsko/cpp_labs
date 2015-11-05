#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(15);
    ui->tableWidget->setColumnCount(15);
    ui->textField->setText("");
    generate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate() {
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(qrand() % 1000));
            item->setBackground(Qt::white);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void MainWindow::on_generate_clicked()
{
    generate();
}

void MainWindow::on_findMax_clicked()
{
    double max = 0;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            item->setBackground(Qt::white);
            double val = item->text().toDouble();
            if(val > max) {
                max = val;
            }
        }
    }
    ui->textField->setText("Максимальное число: " + QString::number(max));
    QMessageBox::information(this, "Максимальное число", "Максимальное число: " + QString::number(max));
}

void MainWindow::on_calc2_clicked()
{
    int count = 0;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            int val = item->text().toInt();
            if(checkIfPowerOf2(val)) {
                item->setBackground(Qt::red);
                count++;
            }
        }
    }
    ui->textField->setText("Степеней двойки: " + QString::number(count));
    QMessageBox::information(this, "Степени двойки", "Найдено: " + QString::number(count));
}

void MainWindow::on_calc3_clicked()
{
    int count = 0;
    for(int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for(int j = 0; j < ui->tableWidget->columnCount(); j++) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            int val = item->text().toInt();
            if(checkIfPowerOf3(val)) {
                item->setBackground(Qt::blue);
                count++;
            }
        }
    }
    ui->textField->setText("Степеней тройки: " + QString::number(count));
    QMessageBox::information(this, "Степени тройки", "Найдено: " + QString::number(count));
}

bool MainWindow::checkIfPowerOf3(int val) {
    double a = val;
    while(a >= 3) {
        a = a / 3;
    }
    return a == 1;
}

bool MainWindow::checkIfPowerOf2(int val) {
    return !(val & (val-1));
}
