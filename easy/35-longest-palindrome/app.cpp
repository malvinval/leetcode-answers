#include <iostream>
#include <unordered_map>
#include <string>

/**
 * Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

    Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

    Example 1:

    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
    
    Example 2:

    Input: s = "a"
    Output: 1
    Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/

int longestPalindrome(std::string s) {
    std::unordered_map<char, int> charOccurence;
    
    int longestPalindrome {0};
    bool oddFound {false};

    /**
     * Algorithm:
     * 
     * 1. Count the quantity of all characters
     * 2. There can only be 1 character that has an odd quantity.
     * 3. If there are other characters with an odd quantity, reduce their quantity by 1.
     * 4. Sum up the quantities of all the letters.
    */
   
    for(char ss : s) {
        charOccurence[ss]++;
    }

    for(std::pair<char, int> c : charOccurence) {
        if(c.second % 2 == 1) {
            if(oddFound == true) {
                c.second -= 1;
                longestPalindrome += c.second;
            } else longestPalindrome += c.second; oddFound = true;
        } else {
            longestPalindrome += c.second;
        }
    }

    return longestPalindrome;
}

int main() {
    std::cout << longestPalindrome("bananas") << std::endl;

    return 0;
}
