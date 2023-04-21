#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

/**
 * Write an algorithm to determine if a nber n is happy.

    A happy number is a number defined by the following process:

    Starting with any positive integer, replace the nber by the sum of the squares of its digits.

    Repeat the process until the nber equals 1 (where it will stay),
    or it loops endlessly in a cycle which does not include 1.
    
    Those nbers for which this process ends in 1 are happy.
    Return true if n is a happy nber, and false if not.

    Example 1:

    Input: n = 19
    Output: true
    Explanation:
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1
    
    Example 2:

    Input: n = 2
    Output: false
*/

int squareAndSum(int n) {
    int sum = 0, digit;
    
    while (n > 0) {
        digit = n % 10; // take last digit of n. ex: n = 49, so digit = 9
        sum += pow(digit, 2);
        n /= 10; // take first digit of n. ex: n = 49, then next n will be 4.
    }

    return sum;
}

bool isHappy(int n) {
    std::vector<int> seenNumber;

    // std::find(seenNumber.begin(), seenNumber.end(), n) == seenNumber.end() is used to find if value of n already pushed in vector before.
    while ( n != 1 && std::find(seenNumber.begin(), seenNumber.end(), n) == seenNumber.end() ) {
        seenNumber.push_back(n);
        n = squareAndSum(n);
    }

    return n == 1 ? true:false;
}

/**
 * Execution steps:
 * 
 * 1. Initialize an empty vector seen to keep track of seen numbers.
 * 2. Calculate the square sum of 7, which is 7^2 = 49.
 * 3. Since we haven't seen 49 before, add it to the seen vector.
 * 4. Calculate the square sum of 49, which is 4^2 + 9^2 = 16 + 81 = 97.
 * 5. Since we haven't seen 97 before, add it to the seen vector.
 * 6. Calculate the square sum of 97, which is 9^2 + 7^2 = 81 + 49 = 130.
 * 7. Since we haven't seen 130 before, add it to the seen vector.
 * 8. Calculate the square sum of 130, which is 1^2 + 3^2 + 0^2 = 10.
 * 9. Since we haven't seen 10 before, add it to the seen vector.
 * 10. Calculate the square sum of 10, which is 1^2 + 0^2 = 1.
 * 11. Since we've found 1, the number is happy, and the function returns true.
*/

/**
 * Why we need vector ?
 * 
 * If we've seen a number before in the 'seenNumber' vector, it means that we have entered a cycle of non-happy numbers,
 * and we should stop the calculation and return false.
 * 
 * This is because once we enter a cycle of non-happy numbers,
 * we will keep generating the same sequence of numbers over and over again, without ever reaching 1.
 * 
 * Therefore, if we've already seen a number, we know that we have entered a cycle,
 * and there's no need to continue the calculation, as it will not lead to a happy number.
*/

int main() {
    std::cout << isHappy(7) << std::endl;
    return 0;
}