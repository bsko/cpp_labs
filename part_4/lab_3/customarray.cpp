#include <customarray.h>

template<class T1> CustomArray<T1>::CustomArray(T1 data[]) {
    this->data = data;
}

template<class T1> CustomArray<T1>::~CustomArray() {
//    delete data;
//    data = 0;
}

template<class T1> T1* CustomArray<T1>::createSubarray() {
   return &data;
}
