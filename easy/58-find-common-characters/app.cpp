#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

/**
 * Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

    Example 1:

    Input: words = ["bella","label","roller"]
    Output: ["e","l","l"]

    Example 2:

    Input: words = ["cool","lock","cook"]
    Output: ["c","o"]
*/

std::vector<std::string> commonChars(std::vector<std::string>& words) {
    std::vector<std::string> commonCharacters;
    std::unordered_map<char, int> charAndFreq;

    int i = 0;
    int j = 0;
    int wordsVecSize = words.size();

    // count all chars
    while (i < wordsVecSize) {
        while (j < words[i].length()) {
            charAndFreq[words[i][j]]++;
            j++;
        }
        i++;
        j = 0;
    }

    // if quantity of char is smaller than vector size, remove it from hashmap
    for (std::unordered_map<char, int>::iterator it = charAndFreq.begin(); it != charAndFreq.end();) {
        if ((*it).second < wordsVecSize) {
            it = charAndFreq.erase(it);
        } else ++it;
    }

    // make sure if all counted chars in hashmap exist in all strings
    i = 0;
    for (std::pair<char, int> caf : charAndFreq) {
        while (i < wordsVecSize) {
            if(words[i].find(caf.first) == std::string::npos) {
                charAndFreq[caf.first] = 0;
            }   
            i++;
        }
        i = 0;
    }

    // determine how many times (hmt) should we push a character based on their duplications.
    for(std::pair<char, int> caf : charAndFreq) {
        int hmt {0};
        int counter {0};
        if(caf.second != 0) {
            int i = 0;
            int j = 0;

            while (i < wordsVecSize) {
                while (j < words[i].length()) {
                    if(words[i][j] == caf.first) counter += 1;
                    j++;
                }

                if(hmt == 0) hmt = counter;
                else {
                    if (counter < hmt) hmt = counter;
                }
                
                i++;
                j = 0;
                counter = 0;
            }
        }

        for (int i = 0; i < hmt; i++) {
            std::string str;
            str.push_back(caf.first);
            commonCharacters.push_back(str);
        }
    }

    return commonCharacters; 
}

int main() {
    std::vector<std::string> words {"bbddabab","cbcddbdd","bbcadcab","dabcacad","cddcacbc","ccbdbcba","cbddaccc","accdcdbb"};

    commonChars(words);

    return EXIT_SUCCESS;
}

