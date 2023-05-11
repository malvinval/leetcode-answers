#include <iostream>
#include <algorithm>

/**
 * Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

    Example 1:

    Input: s = "Hello"
    Output: "hello"

    Example 2:

    Input: s = "here"
    Output: "here"
    Example 3:

    Input: s = "LOVELY"
    Output: "lovely"
*/

std::string toLowerCase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main() {
    std::cout << toLowerCase("OKAY") << "\n";
    return EXIT_SUCCESS;
}