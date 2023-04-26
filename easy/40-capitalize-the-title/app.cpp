#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>

/**
 * You are given a string title consisting of one or more words separated by a single space,
 * where each word consists of English letters.
 * 
 * Capitalize the string by changing the capitalization of each word such that:

    - If the length of the word is 1 or 2 letters, change all letters to lowercase.
    - Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
    - Return the capitalized title.
*/

std::string capitalizeTitle(std::string title) {
    std::stringstream ss(title);
    std::string word, capitalizedTitle {""};
    std::vector<std::string> words;

    while (std::getline(ss, word, ' ')) words.push_back(word);
    
    for(int i = 0; i < words.size(); i++) {
        if(words[i].length() <= 2) {
            for(int k = 0; k < words[i].length(); k++) words[i][k] = std::tolower(words[i][k]);
        } else {
            words[i][0] = std::toupper(words[i][0]);
            for(int j = 1; j < words[i].length(); j++) words[i][j] = std::tolower(words[i][j]);
        }

        capitalizedTitle += i == words.size() - 1 ? words[i] : words[i] + ' ';
    }

    return capitalizedTitle;
}

int main () {
    std::cout << capitalizeTitle("First leTTeR Of EACH Word") << std::endl;
    return EXIT_SUCCESS;
}