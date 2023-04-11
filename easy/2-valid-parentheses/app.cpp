#include <iostream>
#include <string>
#include <stack>

/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    
    Example 1:

    Input: s = "()"
    Output: true
*/

bool isValid(std::string s);

int main() {
    std::cout << isValid("[]") << std::endl;
}

bool isValid(std::string s) {
    std::stack<char> ss;

    for(auto c : s) {
        if(s.size() < 2) {
            return false;
        }
        if(c == '(' || c == '{' || c == '[') {
            ss.push(c);
        } else {
            if (ss.empty()) {
                return false;
            }
            bool found_match = false;
            char top = ss.top();
            ss.pop();
            if (c == ')' && top == '(') {
                found_match = true;
            }
            if (c == '}' && top == '{') {
                found_match = true;
            }
            if (c == ']' && top == '[') {
                found_match = true;
            }
            if (!found_match) {
                return false;
            }
        }
    }

    return ss.empty();
}