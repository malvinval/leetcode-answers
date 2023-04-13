#include <iostream>
#include <vector>
#include <cmath>

/**
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below.
    Note that 1 does not map to any letters.

    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    Example 2:

    Input: digits = ""
    Output: []
    
    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]
*/

std::vector<std::string> letterCombinations(std::string digits) {
    // available phone characters
    std::vector<std::string> letters {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // possible characters (ex: string="23", then the value will be = {"abc", "def"})
    std::vector<std::string> possibleLetters {};

    // combinations using possible characters
    std::vector<std::string> combinations {};

    // store possible letters
    for (int i = 0; i < digits.length(); i++) {
        possibleLetters.push_back(letters[digits[i] - '0']);
    }

    // return empty vector if digits is empty string
    if (possibleLetters.empty()) {
        return combinations;
    }

    // make combinations
    int totalCombinations = 1;
    for (int i = 0; i < possibleLetters.size(); i++) {
        totalCombinations *= possibleLetters[i].size();
    }
    for (int i = 0; i < totalCombinations; i++) {
        std::string temp = "";
        int num = i;
        for (int j = 0; j < possibleLetters.size(); j++) {
            int index = num % possibleLetters[j].size();
            temp += possibleLetters[j][index];
            num /= possibleLetters[j].size();
        }
        combinations.push_back(temp);
    }

    return combinations;
}

int main() {
    for(auto c : letterCombinations("23")) {
        std::cout << c << " ";
    }

    return 0;
}