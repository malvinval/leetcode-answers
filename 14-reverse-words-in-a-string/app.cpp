#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/**
 * Given an input string s, reverse the order of the words.

    A word is defined as a sequence of non-space characters.
    The words in s will be separated by at least one space.

    Return a string of the words in reverse order concatenated by a single space.

    Note that s may contain leading or trailing spaces or multiple spaces between two words.
    The returned string should only have a single space separating the words.
    Do not include any extra spaces.

    Example 1:

    Input: s = "the sky is blue"
    Output: "blue is sky the"
    
    Example 2:

    Input: s = "  hello world  "
    Output: "world hello"
    Explanation: Your reversed string should not contain leading or trailing spaces.
    
    Example 3:

    Input: s = "a good   example"
    Output: "example good a"
    Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

std::string reverseWords(std::string s) {
    // store string to stringstream object
    std::stringstream ss(s);

    std::string word, reversedString = "";
    
    std::vector<std::string> words;

    /**
     * '>>' operator treats consecutive whitespace characters as a delimiter and discards them.
     * In simple term, any whitespaces will be ignored (not extracted from stringstream object).
    */
    while(ss >> word) {
        // insert extracted string to vector
        words.insert(words.begin(), word);

        // also insert a whitespace char after an extracted word inserted
        words.insert(words.begin()," ");
    }

    for(std::string w : words) {
        reversedString += w;
    }

    int left = 0;

    // erase leading whitespace char
    if (reversedString[left] == ' ') reversedString.erase(left, 1);

    return reversedString;
}

int main() {
    std::cout << reverseWords("     leetcode   is      love   ") << std::endl;

    return 0;
}