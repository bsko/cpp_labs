#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <officepackage.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setData(OfficePackage data[], int length);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
