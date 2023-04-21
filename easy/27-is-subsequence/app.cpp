#include <iostream>
#include <string>

/**
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

    Example 1:

    Input: s = "abc", t = "ahbgdc"
    Output: true
    
    Example 2:

    Input: s = "axc", t = "ahbgdc"
    Output: false
*/

bool isSubsequence(std::string s, std::string t) {
    int i = 0, j = 0;

    /**
     * In this case, i is used to track s, j is used to track t.
     * 
     * If a character in t matches current character in s, increment both tracker (i and j).
     * If not, only increment j (tracker of t)
    */

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.length();
}

int main() {
    std::cout << isSubsequence("abc", "ahbgdc") << std::endl;

    return 0;
}