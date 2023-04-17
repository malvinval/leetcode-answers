#include <iostream>
#include <string>
#include <algorithm>

/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:

    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:

    Input: s = "rat", t = "car"
    Output: false
*/

bool isAnagram(std::string s, std::string t) {
    // sort both string
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    return s == t ? true : false;
}

int main() {
    std::cout << isAnagram("act", "cat") << std::endl;
    return 0;
}