#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
    return haystack.find(needle);
}

int main() {
    std::cout << strStr("leetcode", "test");
    return 0;
}