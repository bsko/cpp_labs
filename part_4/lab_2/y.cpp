#include <iostream>
#include <y.h>

using namespace std;

y::y(int a, int b, int c) : x::x(a, b) {
    this->c = c;
}

y::~y() {

}

void y::print() {
    cout << "A = " << a << " ; B = " << b << "; C = " << c <<endl;
}

void y::setA(int a) {
    this->a = a;
}

void y::setB(int b) {
    this->b = b;
}

void y::setC(int c) {
    this->c = c;
}
