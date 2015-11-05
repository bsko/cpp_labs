#ifndef CUSTOMARRAY
#define CUSTOMARRAY

#endif // CUSTOMARRAY

template <class T1>
class CustomArray {
public:
    CustomArray(T1 data[]);
    ~CustomArray();
    T1* createSubarray();
private:
    T1 data[];
};
