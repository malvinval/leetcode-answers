#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

    Example 1:

    Input: nums1 = [4,1,3], nums2 = [5,7]
    Output: 15
    Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

    Example 2:

    Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
    Output: 3
    Explanation: The number 3 contains the digit 3 which exists in both arrays.
*/

int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
    int smallestNumber;
    int i {0};
    int j {0};
    bool isMatched {false};
    std::string smallestNumberStr {""};

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    // check if there is a matched number
    while (i < nums1.size())
    {
        while (j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                isMatched = true;
                return nums1[i];
            }
            j++;
        }

        j = 0;
        i++;
    }

    if (nums1[0] < nums2[0]) {
        smallestNumberStr += std::to_string(nums1[0]);
        smallestNumberStr += std::to_string(nums2[0]);
    } else {
        smallestNumberStr += std::to_string(nums2[0]);
        smallestNumberStr += std::to_string(nums1[0]);
    }

    smallestNumber = std::stoi(smallestNumberStr);

    return smallestNumber;
}

int main() {
    std::vector<int> nums1 {7,5,6};
    std::vector<int> nums2 {1,4};

    std::cout << minNumber(nums1, nums2) << std::endl;

    return EXIT_SUCCESS;
}