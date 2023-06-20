#include <iostream>
#include <vector>

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    int i {0};
    int j {0};
    int totalOfSmallerNumberCurr {0};

    std::vector<int> totalOfSmallerNumbers;

    while(i < nums.size()) {
        while (j < nums.size())
        {
            if (i != j) {
                if (nums[j] < nums[i]) {
                    totalOfSmallerNumberCurr += 1;
                }
            }

            if (j == nums.size() - 1) {
                totalOfSmallerNumbers.push_back(totalOfSmallerNumberCurr);
            }
            
            j++;
        }
        
        j = 0;
        totalOfSmallerNumberCurr = 0;
        i++;
    }

    return totalOfSmallerNumbers;
}

int main() {
    std::vector<int> nums {8,1,2,2,3};

    smallerNumbersThanCurrent(nums);

    return EXIT_SUCCESS;
}