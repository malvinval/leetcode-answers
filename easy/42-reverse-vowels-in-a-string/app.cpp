#include <iostream>
#include <string>

/**
 * Given a string s, reverse only all the vowels in the string and return it.

    The vowels are 'a', 'e', 'i', 'o', and 'u'.
    They can appear in both lower and upper cases, more than once.

    Example 1:

    Input: s = "hello"
    Output: "holle"

    Example 2:

    Input: s = "leetcode"
    Output: "leotcede"
*/

bool isVowel(char c) {
    std::string vowels = "aAiIuUeEoO";
    int i = vowels.find(c);
    return i != (int) std::string::npos;
}

void swap(char& x, char& y) {
    char medium = x;
    x = y;
    y = medium;
}

void move(int& i, size_t& j) {
    i += 1;
    j -= 1;
}

void swapAndMove(std::string& s, int& i, size_t& j) {
    swap(s[i], s[j]);
    move(i, j);
}

/**
 * My approach:
 * 
 * 1. Iterate string from both sides. i starts from the beginning, j from the end.
 * 2. If i is vowel but j is not, decrement j until s[j] is vowel.
 * 3. If j is vowel but i is not, decrement i until s[i] is vowel.
 * 4. If s[i] and s[j] vowel, do swapping, increment i, and decrement j.
*/

std::string reverseVowels(std::string s) {
    int i {0};
    size_t j {s.length() - 1};

    while (i < j) {
        if (isVowel(s[i]) && isVowel(s[j])) {
            swapAndMove(s, i, j);
        } else if (isVowel(s[i]) && !isVowel(s[j])) {
            while (i < j && !isVowel(s[j])) j -= 1;
            if (i < j) swapAndMove(s, i, j);
        } else if (!isVowel(s[i]) && isVowel(s[j])) {
            while (i < j && !isVowel(s[i])) i += 1;
            if (i < j) swapAndMove(s, i, j);
        } else {
            move(i, j);
        }
    }
    return s;
}

int main() {
    std::cout << reverseVowels("leetcode") << std::endl;
    return EXIT_SUCCESS;
}

