#include <iostream>

/**
 * Given the head of a singly linked list, return the middle node of the linked list.
    If there are two middle nodes, return the second middle node.

    Input: head = [1,2,3,4,5]
    Output: [3,4,5]
    Explanation: The middle node of the list is node 3.

    Input: head = [1,2,3,4,5,6]
    Output: [4,5,6]
    Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// submit function below to leetcode
ListNode* middleNode(ListNode* head) {
    ListNode* curr = head;
    int totalNodes {0};

    // count total nodes exist
    while (curr != nullptr) {
        totalNodes += 1;
        curr = curr->next;
    }

    // take the middle node
    totalNodes = totalNodes / 2 - 1;

    // iterate until middle node found
    curr = head;
    while (totalNodes >= 0)
    {
        curr = curr->next;
        totalNodes -= 1;
    }
    
    return curr;
}
// submit function above to leetcode

void print(ListNode* head) {
    ListNode* curr = head;

    while (curr != nullptr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

int main() {
    ListNode node6 = ListNode(6);
    ListNode node5 = ListNode(5, &node6);
    ListNode node4 = ListNode(4, &node5);
    ListNode node3 = ListNode(3, &node4);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);

    // print(&node1);
    std::cout << middleNode(&node1)->val;

    return EXIT_SUCCESS;
}