#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

    A substring is a contiguous sequence of characters within a string

    Example 1:

    Input: words = ["mass","as","hero","superhero"]
    Output: ["as","hero"]
    Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
    ["hero","as"] is also a valid answer.
    Example 2:

    Input: words = ["leetcode","et","code"]
    Output: ["et","code"]
    Explanation: "et", "code" are substring of "leetcode".
    Example 3:

    Input: words = ["blue","green","bu"]
    Output: []
    Explanation: No string of words is substring of another string.
*/

std::vector<std::string> stringMatching(std::vector<std::string>& words) {
    std::vector<std::string> substrings;

    int i = 0;
    int j = 0;

    while (i < words.size()) {
        while (j < words.size()) {
            if (i != j) {
                std::string::iterator it = std::search(words[i].begin(), words[i].end(), words[j].begin(), words[j].end());

                if (it != words[i].end()) {
                    if(std::find(substrings.begin(), substrings.end(), words[j]) == substrings.end()) {
                        substrings.push_back(words[j]);
                    }
                }
            }
            j++;
        }
        i++;
        j = 0;
    }

    for (std::string s : substrings) std::cout << s << " ";

    return substrings;       
}

int main() {
    std::vector<std::string> words {"leetcoder","leetcode","od","hamlet","am"};
    stringMatching(words);

    return EXIT_SUCCESS;
}