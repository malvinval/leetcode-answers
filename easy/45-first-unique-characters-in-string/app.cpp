#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

    Example 1:

    Input: s = "leetcode"
    Output: 0
    
    Example 2:

    Input: s = "loveleetcode"
    Output: 2
    
    Example 3:

    Input: s = "aabb"
    Output: -1
*/

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> charAndFrequency;

    for(char ss : s) {
        charAndFrequency[ss]++;
    }

    for (char ss : s) {
        if(charAndFrequency[ss] == 1) {
            /**
             * Declare a string iterator to find ss in string.
            */
            std::string::iterator itr = std::find(s.begin(), s.end(), ss);

            /**
             * std::distance return distance of two iterator.
             * in this case, the first iterator is s.begin() and the second one is itr
            */
            return std::distance(s.begin(), itr);
        }
    }

    return -1;
}

int main() {
    std::cout << firstUniqChar("tuvwxyzabcdefghijklmnopqrs") << std::endl;
    return EXIT_SUCCESS;
}