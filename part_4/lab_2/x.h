#ifndef X
#define X

#endif // X

class x {
public:
    x(int a, int b);
    ~x();
    virtual void print();
    virtual void setA(int a);
    virtual void setB(int b);
protected:
    int a, b;
};
