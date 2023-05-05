#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// just submit this code below to leetcode
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    
    while (curr != nullptr && curr->next != nullptr) {
        if(curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}
// just submit code above to leetcode

void print(ListNode* head) {
    ListNode* curr = head;

    while (curr != nullptr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

int main() {
    ListNode node6 = ListNode(4);
    ListNode node5 = ListNode(4, &node6);
    ListNode node4 = ListNode(4, &node5);
    ListNode node3 = ListNode(4, &node4);
    ListNode node2 = ListNode(4, &node3);
    ListNode node1 = ListNode(4, &node2);

    deleteDuplicates(&node1);
    print(&node1);

    return EXIT_SUCCESS;
}