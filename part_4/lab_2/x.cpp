#include <iostream>
#include <x.h>

using namespace std;

x::x(int a, int b) {
    this->a = a;
    this->b = b;
}

x::~x() {

}

void x::print() {
    cout << "A = " << a << " ; B = " << b << endl;
}

void x::setA(int a) {
    this->a = a;
}

void x::setB(int b) {
    this->b = b;
}
