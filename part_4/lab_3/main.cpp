#include <iostream>
#include <cstring>

using namespace std;

template <class T1>
class CustomArray {
public:
    CustomArray(T1* data, int length);
    ~CustomArray();
    T1* createSubarray();
private:
    T1* data;
    int length;
};

template<class T1> CustomArray<T1>::CustomArray(T1* data, int length) {
    this->data = data;
    this->length = length;
}

template<class T1> CustomArray<T1>::~CustomArray() {
    delete data;
    data = 0;
}

template<class T1> T1* CustomArray<T1>::createSubarray() {
    T1* result = new T1[length];
    for(int i = 0; i < length; i++) {
        result[i] = data[i] / (i + 1);
    }
    return result;
}


int main() {
    int length = 3;
    int a[length] = {1, 2, 9};
    CustomArray<int> b(a, length);
    int* result = b.createSubarray();
    for(int i = 0; i < length; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}

