#include <iostream>
#include <vector>

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