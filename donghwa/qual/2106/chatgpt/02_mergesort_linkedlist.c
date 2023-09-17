#include <stdio.h>
#include <stdlib.h>

// Define the structure of a ListNode
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to merge two sorted linked lists
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode* merged = NULL;
    struct ListNode* tail = NULL;

    while (left && right) {
        if (left->data <= right->data) {
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

    if (left) {
        if (!merged) {
            merged = left;
        } else {
            tail->next = left;
        }
    }

    if (right) {
        if (!merged) {
            merged = right;
        } else {
            tail->next = right;
        }
    }

    return merged;
}

// Function to perform merge sort on a linked list
struct ListNode* mergeSort(struct ListNode* head) {
    if (!head || !head->next) {
        return head; // Base case: empty list or single element
    }

    // Split the list into two halves
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* left = head;
    struct ListNode* right = slow->next;
    slow->next = NULL;

    // Recursively sort each half
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct ListNode** head, int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    if (!(*head)) {
        *head = newNode;
        return;
    }

    struct ListNode* current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 10);

    printf("Original List:\n");
    printList(head);

    // Perform merge sort on the linked list
    head = mergeSort(head);

    printf("Sorted List:\n");
    printList(head);

    // Free memory
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
