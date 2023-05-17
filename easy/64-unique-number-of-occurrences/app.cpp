#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

    Example 1:

    Input: arr = [1,2,2,1,1,3]
    Output: true
    Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
    Example 2:

    Input: arr = [1,2]
    Output: false
    Example 3:

    Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    Output: true
*/

bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> numberAndFreq;
    std::unordered_map<int, int> trackNumberAndFreq;

    for(int a : arr) {
        numberAndFreq[a]++;
    }

    for (std::pair<int, int> naf : numberAndFreq) {
        trackNumberAndFreq[naf.second]++;
    }
    
    for (std::pair<int, int> tnaf : trackNumberAndFreq) {
        if(tnaf.second > 1) return false;
    }

    return true;
}

int main() {
    std::vector<int> arr {1,2};

    std::cout << uniqueOccurrences(arr) << "\n";

    return EXIT_SUCCESS;
}