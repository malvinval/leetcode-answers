#include <iostream>
#include <string>

/**
 * We define the usage of capitals in a word to be right when one of the following cases holds:

    - All letters in this word are capitals, like "USA".
    - All letters in this word are not capitals, like "leetcode".
    - Only the first letter in this word is capital, like "Google".
    
    Given a string word, return true if the usage of capitals in it is right.

    Example 1:

    Input: word = "USA"
    Output: true

    Example 2:

    Input: word = "FlaG"
    Output: false
*/

bool checkCapital(char c) {
    // check if capital or not
    if(c == std::toupper(c)) {
        return true;
    }
    return false;
}

bool detectCapitalUse(std::string word) {
    int totalCapitalChars {0};

    for(int i = 0; i < word.length(); i++) {
        if ( checkCapital(word[i]) ) totalCapitalChars += 1;
    }
    
    return ((checkCapital(word[0]) && totalCapitalChars == 1) || totalCapitalChars == word.length() || totalCapitalChars == 0);
}

int main() {
    std::cout << detectCapitalUse("g") << std::endl;
    return EXIT_SUCCESS;
}