#include <iostream>
#include <string>

/**
 * Given an integer n, add a dot (".") as the thousands separator and return it in string format.

    Example 1:

    Input: n = 987
    Output: "987"
    
    Example 2:

    Input: n = 1234
    Output: "1.234"
*/

std::string thousandSeparator(int n) {
    // convert number to string
    std::string nS {std::to_string(n)};

    if(n > 999) { // check if the number is thousand(s)
        // do "." insertion from the back of string every 3 digits
        for(int i = nS.length() - 3; i > 0; i -= 3) {
            nS.insert(i, ".");
        }
    }

    return nS;
}

int main() {
    std::cout << thousandSeparator(11111111) << std::endl;
}