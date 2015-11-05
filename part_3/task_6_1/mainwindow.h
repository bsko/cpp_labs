#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_generate_clicked();

    void on_findMax_clicked();

    void on_calc2_clicked();

    void on_calc3_clicked();

private:
    Ui::MainWindow *ui;
    void generate();
    bool checkIfPowerOf3(int val);
    bool checkIfPowerOf2(int val);
};

#endif // MAINWINDOW_H
