#include <iostream>
#include <vector>
#include <numeric>

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