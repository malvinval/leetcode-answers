#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> fbVec;

    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0 && i % 5 == 0) fbVec.push_back("FizzBuzz");
        else if(i % 3 == 0) fbVec.push_back("Fizz");
        else if(i % 5 == 0) fbVec.push_back("Buzz");
        else fbVec.push_back(std::to_string(i));
    };

    return fbVec;
}

int main() {
    fizzBuzz(15);

    return EXIT_SUCCESS;
}