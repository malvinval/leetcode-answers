#include <iostream>
#include <unordered_map>
#include <string>

/**
 * Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

    Given a balanced string s, split it into some number of substrings such that:

    Each substring is balanced.
    Return the maximum number of balanced strings you can obtain.

    Example 1:

    Input: s = "RLRRLLRLRL"
    Output: 4
    Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
    
    Example 2:

    Input: s = "RLRRRLLRLL"
    Output: 2
    Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
    Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
    
    Example 3:

    Input: s = "LLLLRRRR"
    Output: 1
    Explanation: s can be split into "LLLLRRRR".
*/

int balancedStringSplit(std::string s) {
    std::unordered_map<char, int> charAndFreq;
    int balancedSubstring {0};

    for(char ss : s) {
        charAndFreq[ss] += 1;

        if(charAndFreq['R'] == charAndFreq['L']) {
            balancedSubstring += 1;
            for(std::pair<char, int> CAF : charAndFreq) {
                CAF.second = 0;
            }
        }
    }

    return balancedSubstring;
}

int main() {
    std::cout << balancedStringSplit("RLRRRLLRLL") << std::endl;
    return EXIT_SUCCESS;
}