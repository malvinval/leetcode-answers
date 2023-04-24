#include <iostream>
#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.size() == 1) return strs[0];
    if (strs.empty()) return "";

    std::string commonprefix {""};

    /**
     * i is used to handle only first string element in strs vector
     * j is used to handle the rest, start from the last element.
    */
    int i = 0, j = strs.size() - 1;

    // just read this code thoroughly, you will easily understand. i promise!
    while (true) {
        if (i < strs[0].length() && strs[0][i] == strs[j][i]) {
            if(j == 0) {
                commonprefix += strs[0][i];
                i += 1;
                j = strs.size() - 1;
            } else {
                j -= 1;
            }
        } else break;
    }
    
    return commonprefix;
}

int main() {
    std::vector<std::string> strs {"flower", "flower", "flower", "flower"};
    std::cout << longestCommonPrefix(strs) << std::endl;

    return EXIT_SUCCESS;
}