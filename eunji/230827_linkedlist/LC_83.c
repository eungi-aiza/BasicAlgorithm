#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 struct ListNode {
    /* Definition for singly-linked list.*/
     int val;
     struct ListNode *next;
 };


struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || !head->next) 
        return head;

    struct ListNode* ans = head;
    while (head) {
        struct ListNode* temp = head->next;
        int skip = 0;
        while (temp && temp->val == head->val) {
            temp = temp->next;
            skip++;
        }
        struct ListNode* temp2 = head->next;
        for (int i = 0; i < skip; i++) {
            temp2 = temp2->next;
        }
        head->next = temp2;
        head = temp;
    }

    return ans;
}

int main() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;

    // Create nodes for the linked list
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1;
    node1->next = NULL;

    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 1;
    node2->next = NULL;

    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 1;
    node3->next = NULL;

    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 3;
    node4->next = NULL;

    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node5->val = 3;
    node5->next = NULL;

    // Connect nodes to form the linked list
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Print the linked list
    current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    current = deleteDuplicates(head);
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");

    // Free allocated memory for the nodes
    current = head;
    while (current != NULL) {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
