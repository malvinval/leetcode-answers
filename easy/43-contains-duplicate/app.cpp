#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Given an integer array nums.R
 * Return true if any value appears at least twice in the array.
 * Return false if every element is distinct.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: true
    Example 2:

    Input: nums = [1,2,3,4]
    Output: false
    Example 3:

    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true
*/

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> numAndFrequency;

    for (int n : nums) numAndFrequency[n]++;

    for(std::pair<int, int> NAF : numAndFrequency) {
        if (NAF.second > 1) return true;
    }

    return false;
}

int main() {
    std::vector<int> nums {1,1,1,3,3,4,3,2,4,2};
    std::cout << containsDuplicate(nums) << std::endl;
    return EXIT_SUCCESS;
}