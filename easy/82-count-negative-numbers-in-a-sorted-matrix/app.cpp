#include <iostream>
#include <vector>

/**
 * Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    Example 1:

    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.
    Example 2:

    Input: grid = [[3,2],[1,0]]
    Output: 0
*/

int countNegatives(std::vector<std::vector<int>>& grid) {
    int totalNegativeNum {0};
    int i {0};
    int j {0};

    while (i < grid.size()) {
        while (j < grid[i].size()) {
            if (grid[i][j] < 0) {
                totalNegativeNum += 1;
            }
            j++;
        }
        j = 0;
        i++;
    }

    return totalNegativeNum;
}

int main() {
    std::vector<std::vector<int>> grid {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    std::cout << countNegatives(grid) << std::endl;

    return EXIT_SUCCESS;
}