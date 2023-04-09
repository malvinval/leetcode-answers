#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    There is only one repeated number in nums, return this repeated number.

    You must solve the problem without modifying the array nums and uses only constant extra space.

    Example 1:

    Input: nums = [1,3,4,2,2]
    Output: 2
    
    Example 2:

    Input: nums = [3,1,3,4,2]
    Output: 3
*/

int findDuplicate(std::vector<int>& nums) {
    // <key:number, value:frequency> pairing
    std::unordered_map<int, int> numAndFrequency;

    // vector contains duplicated numbers
    int duplicatedNums;

    // store all elements in nums vector to unordered map, increment the frequency (as the value).
    for (int i = 0; i < nums.size(); i++) numAndFrequency[nums[i]]++;
    
    // store duplicated numbers to a variable
    // optionally, you can replace std::pair<const int, int> with auto type
    for (std::pair<const int, int> NAF : numAndFrequency) {
        if (NAF.second > 1) duplicatedNums = NAF.first;
    }

    return duplicatedNums;
}

int main() {
    std::vector<int> nums {3,1,3,4,2};

    std::cout << findDuplicate(nums) << std::endl;

    return 0;
}