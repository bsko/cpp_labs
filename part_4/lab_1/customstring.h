#ifndef CUSTOMSTRING
#define CUSTOMSTRING
#endif // CUSTOMSTRING

class CustomString {
public:
    CustomString();
    ~CustomString();
    void setValue(char t[]);
    void print();
    void operator=(const CustomString& right);
private:
    char *data;
};

