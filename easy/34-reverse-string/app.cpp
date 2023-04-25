#include <iostream>
#include <vector>

/**
 * Write a function that reverses a string. The input string is given as an array of characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.

    Example 1:

    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]

    Example 2:

    Input: s = ["H","a","n","n","a","h"]
    Output: ["h","a","n","n","a","H"]
*/

void reverseString(std::vector<char>& s) {
    char medium;
    int i {0}, j = s.size() - 1;

    // swapping elements (i starts from beginning, j starts from the end)
    // i and j will "meet" in the middle
    while (i < j) {
        if (s[i] != s[j]) {
            medium = s[j];
            s[j] = s[i];
            s[i] = medium;
        }
        i++;
        j--;
    }

    // another approach (not recommended bcs the runtime is higher)
    // std::reverse(s.begin(), s.end());
}

int main() {
    std::vector<char> s = {'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a'};
    reverseString(s);
    for(char ss : s) {
        std::cout << ss;
    }
    return EXIT_SUCCESS;
}

