#include <iostream>

/**
 * Given the head of a linked list and an integer val.
 * Remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// just submit this function to leetcode
ListNode* removeElements(ListNode* head, int val) {
    // check if head is not null and it's value.
    while (head != nullptr && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // check if head is null
    if (head == nullptr) {
        return nullptr;
    }

    // do deletions
    ListNode* prev = head;
    ListNode* curr = head->next;

    while(curr != nullptr) {
        if(curr->val == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            curr = curr->next;
            prev = prev->next;
        }
    }

    return head;
}

int main() {
    ListNode* node4 = new ListNode(3, nullptr);
    ListNode* node3 = new ListNode(5, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    std::cout << removeElements(node1, 1)->val << std::endl;

    return EXIT_SUCCESS;
}