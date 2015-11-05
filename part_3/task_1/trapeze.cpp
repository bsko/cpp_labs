#include <trapeze.h>


Trapeze::Trapeze(QPainter *p, int a, int b, int h, QString color) {
    this->p = p;
    this->a = a;
    this->b = b;
    this->h = h;
    this->color = color;
    this->visible = true;
}

Trapeze::~Trapeze() {
    delete p;
    p = 0;
}

void Trapeze::setVisible(bool a) {
    visible = a;
}

void Trapeze::setColor(QString color) {
    this->color = color;
}

void Trapeze::draw(int x, int y) {
    if(visible) {
        double upperLeft = x + ((b - a) / 2);
        double upperRight = a + upperLeft;
        QPainterPath path;
        path.moveTo (x, y + h);
        path.lineTo (x + b, y + h);
        path.lineTo (upperRight, y);
        path.lineTo (upperLeft, y);
        path.lineTo (x, y + h);
        p->fillPath (path, QBrush (QColor (color)));
    }
}

void Trapeze::multiply(double m) {
    this->a = a * m;
    this->b = b * m;
    this->h = h * m;
}

void Trapeze::operator=(const Trapeze& right) {
    this->p = right.p;
    this->a = right.a;
    this->b = right.b;
    this->h = right.h;
    this->color = right.color;
    this->visible = right.visible;
}
