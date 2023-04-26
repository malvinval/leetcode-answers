#include <iostream>
#include <string>

bool checkPalindrome(std::string& s, int i, int j) {
    // check if modified string palindrome
    while(i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i += 1;
        j -= 1;
    }

    return true;
}

bool validPalindrome(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    
    while (i <= j)
    {
        if (s[i] == s[j])
            i++, j--;
        else
            /**
             * the 2nd or 3rd params below implements "deleting at most one character from it"
            */
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
    }
    return true;
}


int main() {
    std::cout << validPalindrome("abca") << std::endl;
    return EXIT_SUCCESS;
}