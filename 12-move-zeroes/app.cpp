#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Example 1:

    Input: nums = [4,2,4,0,0,3,0,5,1,0]
    Output: [4,2,4,3,5,1,0,0,0,0]
*/

void moveZeroes(std::vector<int>& nums) {
    int zeroes {0};
        
    for (int n : nums) {
        if (n == 0) zeroes++;
    }

    nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());

    for (int i = 0; i < zeroes; i++) {
        nums.push_back(0);
    }
}

int main() {
    std::vector<int> nums {4,2,4,0,0,3,0,5,1,0};

    moveZeroes(nums);

    return 0;
}