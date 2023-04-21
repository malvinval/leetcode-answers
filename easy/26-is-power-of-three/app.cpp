#include <iostream>

/**
 * Given an integer n, return true if it is a power of three. Otherwise, return false.

    An integer n is a power of three, if there exists an integer x such that n == 3^x.

    Example 1:

    Input: n = 27
    Output: true
    Explanation: 27 = 33
    
    Example 2:

    Input: n = 0
    Output: false
    Explanation: There is no x where 3^x = 0.
*/

bool isPowerOfThree(int n) {
    double fn = (double) n;
    while(fn > 1.0f) fn /= 3.0f;
    return fn == 1.0f;
}

int main() {
    std::cout << isPowerOfThree(45) << std::endl;
    return 0;
}