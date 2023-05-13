#include <iostream>
#include <vector>

/**
 * You are given an array of strings words and a string chars.

    A string is good if it can be formed by characters from chars (each character can only be used once).

    Return the sum of lengths of all good strings in words.

    Example 1:

    Input: words = ["cat","bt","hat","tree"], chars = "atach"
    Output: 6
    Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
    
    Example 2:

    Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    Output: 10
    Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
*/

int countCharacters(std::vector<std::string>& words, std::string chars) {
    int i = 0;
    int j = 0;
    std::string charsMem = chars;

    std::string formedWords {""};
    
    while (i < words.size()) {
        int singleWordSize = 0;
        while (j < words[i].length()) {
            if(chars.find(words[i][j]) != std::string::npos) {
                singleWordSize += 1;
                chars.erase(chars.find(words[i][j]), 1);
            }
            j++;
        }
        if(singleWordSize == words[i].length()){
            formedWords += words[i];
        }
        i++;
        j = 0;
        chars = charsMem;
    }
    
    int formedWordsSize = formedWords.length();

    return formedWordsSize;
}

int main() {
    std::vector<std::string> words {"hello","world","leetcode"};
    std::cout << countCharacters(words, "welldonehoneyr");
    return EXIT_SUCCESS;
}