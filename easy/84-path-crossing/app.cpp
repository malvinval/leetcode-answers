#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

/**
 * Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

    Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

    Example 1:


    Input: path = "NES"
    Output: false 
    Explanation: Notice that the path doesn't cross any point more than once.
    Example 2:


    Input: path = "NESWW"
    Output: true
    Explanation: Notice that the path visits the origin twice.

    URL: https://leetcode.com/problems/path-crossing/
*/

bool isPathCrossing(std::string path) {
    int x = 0;
    int y = 0;

    std::unordered_map<char, std::pair<int, int>> direction;
    std::vector<std::pair<int,int>> visited;

    visited.push_back(std::make_pair(0, 0));

    direction.insert(std::make_pair('N', std::make_pair(0,1)));
    direction.insert(std::make_pair('E', std::make_pair(1,0)));
    direction.insert(std::make_pair('S', std::make_pair(0,-1)));
    direction.insert(std::make_pair('W', std::make_pair(-1,0)));

    for(char p : path) {
        x = x + direction[p].first;
        y = y + direction[p].second;

        auto it = std::find(visited.begin(), visited.end(), std::pair<int, int>(x, y));

        if(it != visited.end()) {
            return true;
        }

        visited.push_back(std::make_pair(x, y));
    }
    
    return false;
}

int main() {
    std::cout << isPathCrossing("NES") << "\n";

    return EXIT_SUCCESS;
}