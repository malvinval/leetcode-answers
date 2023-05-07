#include <iostream>

/**
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
    Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// just submit code below to leetcode
bool hasCycle(ListNode *head) {
    ListNode* singleStep {head};
    ListNode* doubleStep {head};

    while(doubleStep != nullptr && doubleStep->next != nullptr) {
        singleStep = singleStep->next;
        doubleStep = doubleStep->next->next;

        if(singleStep == doubleStep) return true;
    }

    return false;
}
// just submit code above to leetcode

void printLL(ListNode** head) {
    ListNode* curr = *head;

    while (curr != nullptr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

int main() {
    ListNode* node5 {new ListNode(5)};

    ListNode* node4 {new ListNode(4)};
    node4->next = node5;

    ListNode* node3 {new ListNode(3)};
    node3->next = node4;

    ListNode* node2 {new ListNode(2)};
    node2->next = node3;

    ListNode* node1 {new ListNode(1)};
    node1->next = node2;

    printLL(&node1);

    std::cout << hasCycle(node1);

    return EXIT_SUCCESS;
}