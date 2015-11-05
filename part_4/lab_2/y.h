#ifndef Y
#define Y

#endif // Y

#include <x.h>

class y : public x {
public:
    y(int a, int b, int c);
    ~y();
    void print();
    void setA(int a);
    void setB(int b);
    void setC(int c);
protected:
    int c;
};
