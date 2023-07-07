#include <iostream>
#include <vector>

/**
 * A self-dividing number is a number that is divisible by every digit it contains.

    For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
    A self-dividing number is not allowed to contain the digit zero.

    Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

    Example 1:

    Input: left = 1, right = 22
    Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
    Example 2:

    Input: left = 47, right = 85
    Output: [48,55,66,77]
*/

bool isSelfDivide(int num) {
    if (num == 10) {
        return false;
    } else if (num < 10) return true;

    std::vector <int> numDigits {};
    std::string numDigitsStr {std::to_string(num)};
    
    for (char nds : numDigitsStr) {
        numDigits.push_back(nds - '0');
    }

    for (int ndvec : numDigits) {
        if (ndvec == 0 || num % ndvec != 0) {
            return false;
        }
    }

    return true;
} 

std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector <int> selfDivNumbers {};
    int i {left};

    while (i <= right)
    {
        if (isSelfDivide(i)) selfDivNumbers.push_back(i);
        i++; 
    }

    for (int sdnvec : selfDivNumbers) {
        std::cout << sdnvec << " ";
    }
    
    return selfDivNumbers;
}

int main() {
    selfDividingNumbers(1, 22);

    return EXIT_SUCCESS;
}