#include <iostream>
#include <math.h>

using namespace std;

double computeDivider(double *x) {
    double val = *x;
    double result = 2 * val + pow(val, 2);
    if(result == 0) { throw val; }
    else { return result; }
}

double computeFirst(double* x) {
    double val = *x;
    try {
        double div = computeDivider(x);
        return pow(2 + ((1 + val + pow(val, 2)) / div) - ((1 - val + pow(val, 2)) / div), -1) * (5 - 2 * pow(val, 2));
    } catch(...) {
        cout << "Invalid value" << endl;
        return -1;
    }
}

double computeSecond(double* x) {
    double val = *x;
    return (4 - pow(val, 2)) / 2;
}

int main() {
    double x = 0;
    cout << computeFirst(&x) << endl;
    cout << computeSecond(&x) << endl;
    return 0;
}
