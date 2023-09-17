#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* left, ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    ListNode* merged = nullptr;
    ListNode* tail = nullptr;

    while (left && right) {
        if (left->val <= right->val) {
            if (!merged) {
                merged = left;
                tail = left;
            } else {
                tail->next = left;
                tail = left;
            }
            left = left->next;
        } else {
            if (!merged) {
                merged = right;
                tail = right;
            } else {
                tail->next = right;
                tail = right;
            }
            right = right->next;
        }
    }

    if (left) tail->next = left;
    if (right) tail->next = right;

    return merged;
}

ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* left = head;
    ListNode* right = slow->next;
    slow->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = nullptr;

    // Insert elements into the linked list
    head = new ListNode(12);
    head->next = new ListNode(11);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = new ListNode(10);

    std::cout << "Original List:" << std::endl;
    printList(head);

    // Perform merge sort on the linked list
    head = mergeSort(head);

    std::cout << "Sorted List:" << std::endl;
    printList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
