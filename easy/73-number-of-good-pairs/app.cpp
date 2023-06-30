#include <iostream>
#include <vector>

int numIdenticalPairs(std::vector<int>& nums) {
    int totalPairs {0};
    int i {0};
    int j;

    while (i < nums.size())
    {
        j = i + 1;
        while (j < nums.size())
        {   
            if (nums[i] == nums[j]) {
                totalPairs += 1;
            }
            j++;
        }
        
        i++;
    }

    return totalPairs;
}


int main() {
    std::vector<int> nums {1,1,1,1};

    std::cout << numIdenticalPairs(nums) << std::endl;

    return EXIT_SUCCESS;
}