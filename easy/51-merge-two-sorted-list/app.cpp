#include <iostream>

/**
 * You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists in a one sorted list.
    The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

    Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* head) {
    ListNode* curr = head;

    while (curr != nullptr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}

// just submit code below to leetcode
void sort(ListNode* head) {
    ListNode* curr;
    bool swapped;

    do {
        curr = head;
        swapped = false;

        while (curr != nullptr && curr->next != nullptr) {
            if(curr->val > curr->next->val) {
                std::swap(curr->val, curr->next->val);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = list1;
    ListNode* curr = list1;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = list2;

    sort(list1);

    return list1;
}
// just submit code above to leetcode

int main() {
    ListNode node12 = ListNode(5);
    ListNode node11 = ListNode(6, &node12);
    ListNode node10 = ListNode(2, &node11);
    ListNode node9 = ListNode(7, &node10);
    ListNode node8 = ListNode(3, &node9);
    ListNode node7 = ListNode(1, &node8);

    ListNode node6 = ListNode(5);
    ListNode node5 = ListNode(6, &node6);
    ListNode node4 = ListNode(2, &node5);
    ListNode node3 = ListNode(7, &node4);
    ListNode node2 = ListNode(3, &node3);
    ListNode node1 = ListNode(1, &node2);

    mergeTwoLists(&node1, &node7);
    
    print(&node1);

    return EXIT_SUCCESS;
}