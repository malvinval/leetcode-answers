#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

/**
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
 * and removing all non-alphanumeric characters, it reads the same forward and backward.
 * Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:

    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
*/

bool isPalindrome(std::string s) {
    // transform all chars to lowercase
    for (char& c : s) {
        c = std::tolower(c);
    }

    // erase all non-alphanumeric
    for (auto it = s.begin(); it != s.end();) {
        if (!std::isalnum(*it)) {
            it = s.erase(it);
        } else {
            ++it;
        }
    }

    // palindrome check
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;       
}

int main() {
    std::cout << isPalindrome("A man, a plan, a canal: Panama") << std::endl;

    return 0;
}