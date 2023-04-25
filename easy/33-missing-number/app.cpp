#include <iostream>
#include <vector>
#include <numeric>

/**
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

    Example 1:

    Input: nums = [3,0,1]
    Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
    
    Example 2:

    Input: nums = [0,1]
    Output: 2
    Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
    
    Example 3:

    Input: nums = [9,6,4,2,3,5,7,0,1]
    Output: 8
    Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
*/

int missingNumber(std::vector<int>& nums) {
    int expectedAccumulation {0};

    // count expected accumulation
    // example: vector size = 9. expected accumulation = 0+1+2+3+4+5+6+7+8+9
    for (int i = 0; i <= nums.size(); i++) expectedAccumulation += i;

    // count actual accumulation using accumulate function in numeric library
    // example: vector = {9,6,4,2,3,5,7,0,1}. actual accumulation = 9+6+4+2+3+5+7+0+1
    int actualAccumulation = std::accumulate(nums.begin(), nums.end(), 0);

    // missing number = expectedAccumulation - actualAccumulation
    return expectedAccumulation - actualAccumulation;
}

int main() {
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};

    std::cout << missingNumber(nums) << std::endl;
    
    return EXIT_SUCCESS;
}