#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// just submit this function to leetcode
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* curr = head;

    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


int main() {
    ListNode* node2 = new ListNode(2, nullptr);
    ListNode* node1 = new ListNode(1, node2);
    reverseList(node1);
    return EXIT_SUCCESS;
}