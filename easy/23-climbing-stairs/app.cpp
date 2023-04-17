#include <iostream>
#include <vector>

/**
 * You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps.
    In how many distinct ways can you climb to the top?

    Example 1:

    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Example 2:

    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step 
*/

int climbStairs(int n) {
    /**
     * if n is 5, the output must be 8. explanation:
     *  - 1 + 1 + 1 + 1 + 1
     *  - 1 + 1 + 1 + 2
     *  - 1 + 1 + 2 + 1
     *  - 1 + 2 + 1 + 1
     *  - 1 + 2 + 2
     *  - 2 + 1 + 1 + 1
     *  - 2 + 2 + 1
     *  - 2 + 1 + 2
     * 
     * if n is 3, the output must be 5. explanation
     *  - 1 + 1 + 1
     *  - 1 + 2
     *  - 2 + 1
     * 
     * 3 -> 5
     * 5 -> 8
     * that is the concept of fibonacci
     * 
    */

    std::vector<long> fibonacci {};

    long f1 = 1, f2 = 2;
    long fn;

    fibonacci.push_back(f1);
    fibonacci.push_back(f2);

    for (int i = 0; i < n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;

        fibonacci.push_back(fn);
    }

    return fibonacci[n - 1];
}

int main() {
    std::cout << climbStairs(44) << std::endl;
    return 0;
}