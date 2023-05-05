#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    std::string listString {""};
    ListNode* curr = head;

    while (curr != nullptr) {
        listString += std::to_string(curr->val);
        curr = curr->next;
    }

    std::string listString2 {listString};
    
    std::reverse(listString.begin(), listString.end());

    return listString == listString2;
}

int main() {
    ListNode node6 = ListNode(1);
    ListNode node5 = ListNode(2, &node6);
    ListNode node4 = ListNode(2, &node5);
    ListNode node3 = ListNode(2, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);

    std::cout << isPalindrome(&node1) << std::endl;

    return EXIT_SUCCESS;
}