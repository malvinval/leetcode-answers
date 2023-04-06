#include <iostream>

/**
 * Given an integer x, return true if x is a palindrome, and false otherwise.

    Example 1:

    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.
*/
bool isPalindrome(int x) {
    int temporaryNum = 0; // 111

    if(x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    while(x > temporaryNum) {
        temporaryNum = temporaryNum * 10 + x % 10; // 110 + 1
        x /= 10; // 1
    }

    return x == temporaryNum || x == temporaryNum / 10;
}
int main() {
    isPalindrome(121);
    return 0;
}