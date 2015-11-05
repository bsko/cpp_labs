#include <iostream>
#include <customstring.h>

using namespace std;

int main()
{
    char arr[100];
    cin >> arr;

    CustomString *p = new CustomString();
    CustomString *p1 = new CustomString();
    p->setValue(arr);
    *p1 = *p;
    p1->print();

    delete p, p1;
    return 0;
}

