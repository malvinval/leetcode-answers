#include <iostream>
#include <cmath>

/**
 * Given an integer n, return true if it is a power of four. Otherwise, return false.

    An integer n is a power of four, if there exists an integer x such that n == 4x.

    Example 1:

    Input: n = 16
    Output: true
    
    Example 2:

    Input: n = 5
    Output: false
    
    Example 3:

    Input: n = 1
    Output: true
*/

bool isPowerOfFour(int n) {
    if (n == 1) return true;

    int m = n, o {0};

    while(m >= 4) {
        m /= 4;
        o += 1;
    }
    
    return (m == 1 && pow(4, o) == n);
}

int main() {
    std::cout << isPowerOfFour(5) << std::endl;
    return EXIT_SUCCESS;
}