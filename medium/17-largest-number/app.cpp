#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * The custom comparison function takes two arguments of the same type as the elements being sorted,
 * and returns true if the first argument should come before the second argument in the sorted sequence,
 * or false otherwise. The std::sort() function will use this function to compare elements and sort them accordingly.
*/
static bool compare(std::string a,std::string b) {
    return a + b > b + a;
}

std::string largestNumber(std::vector<int>& nums) {
    std::string largestNumber {""};
    std::vector<std::string> stringNums {};

    for(int i = 0; i < nums.size(); i++) {
        stringNums.push_back(std::to_string(nums[i]));
    }

    // std::sort() function in C++ can be combined with a custom comparison function, such as the compare() function defined below.
    // This tells std::sort() to compare the elements of stringNums using the compare() function rather than the default comparison operator.
    std::sort(stringNums.begin(), stringNums.end(), compare);

    if(stringNums[0] == "0") return "0";

    for(std::string lN : stringNums)
    {
        largestNumber += lN;
    }

    return largestNumber;
}

int main() {
    std::vector<int> nums {3,9,34,5,30};

    std::cout << largestNumber(nums) << std::endl;

    return 0;
}