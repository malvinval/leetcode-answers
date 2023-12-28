#include <iostream>
#include <vector>

/**
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
    Example 2:

    Input: nums = [2,0,1]
    Output: [0,1,2]\
*/

void sortColors(std::vector<int>& nums) {
    int n = nums.size();
    
    // bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    
    for (int n : nums) {
        std::cout << n << std::endl;
    }
}

int main() {
    std::vector<int> nums {2,5,1,7,9,3};

    sortColors(nums);

    return EXIT_SUCCESS;
}