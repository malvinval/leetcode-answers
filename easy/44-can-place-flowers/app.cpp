#include <iostream>
#include <vector>

/**
 * You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

    Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

    Example 1:

    Input: flowerbed = [1,0,0,0,1], n = 1
    Output: true
    
    Example 2:

    Input: flowerbed = [1,0,0,0,1], n = 2
    Output: false
*/

void placeAndReduceFlower(std::vector<int>& flowerbed, int& flowerPosition, int& flowerStock) {
    flowerbed[flowerPosition] = 1;
    flowerStock -= 1;
}

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int i {0};

    if (n == 0) return true;

    while (i < flowerbed.size()) {
        if(i == 0) {
            if (flowerbed.size() == 1) {
                n -= flowerbed[i] == 0 ? 1 : 0;
                return n == 0;
            }
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                placeAndReduceFlower(flowerbed, i, n);
            }
        } else if (i == flowerbed.size() - 1) {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                placeAndReduceFlower(flowerbed, i, n);
            }
        } else {
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                placeAndReduceFlower(flowerbed, i, n);
            }
        }
        i++;
    }

    return n <= 0;
}

int main() {
    std::vector<int> flowerbed {1,0,0,0,1};
    std::cout << canPlaceFlowers(flowerbed, 1) << std::endl;

    return EXIT_SUCCESS;
}