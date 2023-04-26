#include <iostream>
#include <string>
#include <algorithm>

/**
 * Given two strings ransomNote and magazine.
 * Return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

    Each letter in magazine can only be used once in ransomNote.

    Example 1:

    Input: ransomNote = "a", magazine = "b"
    Output: false
    
    Example 2:

    Input: ransomNote = "aa", magazine = "ab"
    Output: false
    
    Example 3:

    Input: ransomNote = "aa", magazine = "aab"
    Output: true
*/

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::sort(ransomNote.begin(), ransomNote.end());
    std::sort(magazine.begin(), magazine.end());

    int i {0}, j {0}, totalRansomMatched {0};

    while (i < ransomNote.length()) {
        if(ransomNote[i] == magazine[j]) {
            totalRansomMatched += 1;
            i += 1;
            j += 1;
        } else {
            if(j < magazine.length() - 1) j += 1;
            else break;
        }
    }

    return totalRansomMatched == ransomNote.length();
}

int main() {
    std::cout << canConstruct("aa", "ab") << std::endl;
    return EXIT_SUCCESS;
}