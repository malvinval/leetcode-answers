#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/**
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    
    Input: nums = [1,3,5,6], target = 5
    Output: 2
    
    Example 2:

    Input: nums = [1,3,5,6], target = 2
    Output: 1
    
    Example 3:

    Input: nums = [1,3,5,6], target = 7
    Output: 4
*/

int searchInsert(std::vector<int>& nums, int target) {
    std::vector<int>::iterator iterator;

    for(int i = 0; i < nums.size(); i++) {
        iterator = std::find(nums.begin(), nums.end(), target);

        if (iterator != nums.end()) {
            return iterator - nums.begin();
        } else {
            nums.push_back(target);
            std::sort(nums.begin(), nums.end());
            iterator = std::find(nums.begin(), nums.end(), target);
            return iterator - nums.begin();
        }
    }

    return 0;
}

int main() {
    std::vector<int> nums {2,5,6,4};

    std::sort(nums.begin(), nums.end());

    std::cout << searchInsert(nums, 7) << std::endl;

    return 0;
}