#include <iostream>
#include <cmath>

double myPow(double x, int n) {
    return pow(x, n);
}

int main() {
    std::cout << myPow(2.00000, -2) << std::endl;

    return 0;
}