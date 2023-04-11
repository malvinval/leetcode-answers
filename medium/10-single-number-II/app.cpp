#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Given an integer array nums where every element appears three times except for one, which appears exactly once.
 * Find the single element and return it.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,3,2]
    Output: 3
*/

int singleNumber(std::vector<int>& nums) {
    // sort vector in ascending order
    std::sort(nums.begin(), nums.end());

    // comparing elements
    // the limit of this loop set to nums.size() - 1 to prevent heap-buffer-overflow
    for (int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            i += 2;
        } else {
            return nums[i];
        }
    }
    
    // return the target that is placed at the end of vector
    return nums[nums.size() - 1];
}

int main() {
    std::vector<int> nums {0,1,0,1,0,1,99}; // {0,0,0,1,1,1,99}
    std::cout << singleNumber(nums) << std::endl;

    return 0;
}