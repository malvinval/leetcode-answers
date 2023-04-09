#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Given a non-empty array of integers nums, every element appears twice except for one.
 * Find that single one.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,1]
    Output: 1
*/

int singleNumber(std::vector<int>& nums) {
    // sort vector in ascending order
    std::sort(nums.begin(), nums.end());

    // comparing elements
    // the limit of this loop set to nums.size() - 1 to prevent heap-buffer-overflow
    for (int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            i++;
        } else {
            return nums[i];
        }
    }
    
    // return the target that is placed at the end of vector
    return nums[nums.size() - 1];
}

int main() {
    std::vector<int> nums {4,1,2,1,2};

    std::cout << singleNumber(nums) << std::endl;

    return 0;
}