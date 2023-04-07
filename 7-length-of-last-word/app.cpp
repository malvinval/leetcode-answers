#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/**
 * Given a string s consisting of words and spaces,
 * return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.

    Example 1:

    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.
*/

int lengthOfLastWord(std::string s) {
    std::stringstream strstream (s);
    std::string word;
    
    std::vector<std::string> words;

    while(strstream >> word) {
        words.push_back(word);
    }
    
    auto lastWordSize {words[words.size() - 1].length()};

    return lastWordSize;
}

int main() {
    std::cout << lengthOfLastWord("     leet  ") << std::endl;
    return 0;
}