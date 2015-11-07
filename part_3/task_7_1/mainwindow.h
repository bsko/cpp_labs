#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <officepackage.h>
#include "ui_mainwindow.h"

class OfficePackageController;

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTableWidget* getDataTable();
    void setController(OfficePackageController* controller);

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_itemSelectionChanged();

    void on_update_clicked();

private:
    Ui::MainWindow *ui;
    OfficePackageController* controller;
};

#endif // MAINWINDOW_H
