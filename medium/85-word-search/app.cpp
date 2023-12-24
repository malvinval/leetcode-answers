#include <iostream>
#include <vector>
#include <map>

std::vector<std::pair<int, int>> searchInBoard(std::vector<std::vector<char>>& board, char character) {
    std::vector<std::pair<int, int>> positions;

    for (int j = 0; j < board.size(); j++) {
        for (int k = 0; k < board[j].size(); k++) {
            if (board[j][k] == character) {
                positions.push_back(std::make_pair(j, k));
            }
        }
    }

    return positions;
}

bool isAdjacent(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first == b.first && std::abs(a.second - b.second) == 1) ||
           (a.second == b.second && std::abs(a.first - b.first) == 1);
}

bool existHelper(std::vector<std::vector<char>>& board, const std::string& word, int index,
                 std::pair<int, int> currentPosition, std::map<std::pair<int, int>, bool>& visited) {
    if (index == word.length()) {
        return true; // Base case: entire word is found
    }

    if (currentPosition.first < 0 || currentPosition.first >= board.size() ||
        currentPosition.second < 0 || currentPosition.second >= board[0].size() ||
        board[currentPosition.first][currentPosition.second] != word[index] ||
        visited[currentPosition]) {
        return false; // Out of bounds, mismatch, or already visited
    }

    visited[currentPosition] = true; // Mark the cell as visited

    // Explore adjacent cells
    std::pair<int, int> nextPositions[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& nextPosition : nextPositions) {
        std::pair<int, int> next = {currentPosition.first + nextPosition.first, currentPosition.second + nextPosition.second};
        if (existHelper(board, word, index + 1, next, visited)) {
            return true;
        }
    }

    visited[currentPosition] = false; // Mark the cell as unvisited for backtracking
    return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    std::vector<std::vector<std::pair<int, int>>> founded;

    for (char c : word) {
        std::vector<std::pair<int, int>> positions = searchInBoard(board, c);
        if (!positions.empty()) {
            founded.push_back(positions);
        } else {
            return false; // If any character of the word is not found, return false
        }
    }

    std::map<std::pair<int, int>, bool> visited;
    for (const auto& positions : founded) {
        for (const auto& position : positions) {
            if (existHelper(board, word, 0, position, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'A', 'B'},
        {'C', 'D'}
    };

    std::cout << std::boolalpha << exist(board, "ABCD") << "\n"; // Output: false

    return 0;
}
