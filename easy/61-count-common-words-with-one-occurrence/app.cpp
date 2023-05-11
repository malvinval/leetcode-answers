#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

    Example 1:

    Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
    Output: 2
    Explanation:
    - "leetcode" appears exactly once in each of the two arrays. We count this string.
    - "amazing" appears exactly once in each of the two arrays. We count this string.
    - "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
    - "as" appears once in words1, but does not appear in words2. We do not count this string.
    Thus, there are 2 strings that appear exactly once in each of the two arrays.

    Example 2:

    Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
    Output: 0
    Explanation: There are no strings that appear in each of the two arrays.

    Example 3:

    Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
    Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
*/

int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
    std::unordered_map<std::string, int> wordsAndOccurrence;
    int totalWordsWithOneOccurrence {0};

    //declare vector iterator
    std::vector<std::string>::iterator it;

    // count words in words1 vec
    for(std::string w1 : words1) {
        it = std::find(words2.begin(), words2.end(), w1);

        // is current word also exist in words2 vec?
        if (it != words2.end()) {
            wordsAndOccurrence[w1]++;
        }
    }

    // count words in words2 vec
    for(std::string w2 : words2) {
        it = std::find(words1.begin(), words1.end(), w2);

        // is current word also exist in words1 vec?
        if (it != words1.end()) {
            wordsAndOccurrence[w2]++;
        }
    }

    // count occurrence in hashmap.
    for(std::pair<std::string, int> wao : wordsAndOccurrence) {
        if (wao.second == 2) totalWordsWithOneOccurrence += 1;
    }

    return totalWordsWithOneOccurrence;
}

int main() {
    std::vector<std::string> w1 {"leetcode","is","amazing","as","is", "x"};
    std::vector<std::string> w2 {"amazing","leetcode","is", "x"};

    std::cout << countWords(w1, w2) << "\n";

    return EXIT_SUCCESS;
}