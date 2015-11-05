#ifndef TRAPEZE
#define TRAPEZE

#endif // TRAPEZE

#include <QtGui/QPainter>

class Trapeze {
public:
    Trapeze(QPainter* p, int a, int b, int h, QString color);

    ~Trapeze();

    void draw(int x, int y);

    void setVisible(bool a);

    void setColor(QString color);

    void multiply(double m);

    void operator=(const Trapeze& right);

private:
    QPainter* p;
    bool visible;
    int a, b, h;
    QString color;
};
