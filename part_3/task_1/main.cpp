#include <QApplication>
#include <QtGui/QPainter>
#include <QWidget>
#include <trapeze.h>

class myWidget : public QWidget
{
public:
    myWidget (QWidget *parent=0) : QWidget(parent)
    {
    }

    void paintEvent(QPaintEvent *pe)
    {
        QPainter p(this);
        Trapeze z(&p, 50, 100, 50, "blue");
        z.draw(30, 30);

        Trapeze z1 = z;
        z1.setColor("red");
        z1.multiply(2);
        z1.draw(130, 130);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    return a.exec();
}
