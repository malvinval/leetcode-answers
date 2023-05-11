#include <iostream>
#include <vector>

/**
 * Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

    Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

    Example 1:

    Input: arr = [1,0,2,3,0,4,5,0]
    Output: [1,0,0,2,3,0,0,4]
    Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

    Example 2:

    Input: arr = [1,2,3]
    Output: [1,2,3]
    Explanation: After calling your function, the input array is modified to: [1,2,3]
*/

void duplicateZeros(std::vector<int>& arr) {
    int initArrSize = arr.size();

    for(int i = 0; i < initArrSize; i++) {
        if(arr[i] == 0) {
            arr.insert(arr.begin() + i, 0);
            i++;
            arr.pop_back();
        }
    }
}

int main() {
    std::vector<int> arr {1,0,2,3,0,4,5,0};
    duplicateZeros(arr);
    return EXIT_SUCCESS;
}