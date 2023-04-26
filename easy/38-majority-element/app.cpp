#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    Example 1:

    Input: nums = [3,2,3]
    Output: 3

    Example 2:

    Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> numsAndFrequency;

    for(int n : nums) numsAndFrequency[n]++;

    for(std::pair<int, int> NAF : numsAndFrequency) if (NAF.second > nums.size() / 2) return NAF.first;

    return nums[0];
}

int main() {
    std::vector<int> nums = {2,2,1,1,1,2,2};
    std::cout << majorityElement(nums) << std::endl;

    return EXIT_SUCCESS;
}