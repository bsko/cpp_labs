#include <customstring.h>
#include <iostream>
#include <cstring>

using namespace std;

CustomString::CustomString() {
    data = 0;
}

CustomString::~CustomString() {
    delete data;
    data = 0;
}

void CustomString::setValue(char array[]) {
    data = new char[strlen(array)];
    strcpy(data, array);
}

void CustomString::print() {
    cout << data << endl;
}

void CustomString::operator=(const CustomString& right) {
    data = new char[strlen(right.data)];
    for(int i = 0; i < strlen(right.data); i++) {
        if(right.data[i] != '(' && right.data[i] != ')') {
            data[i] = right.data[i];
        } else {
            break;
        }
    }
}
