/**
 * Definition for singly-linked list in C.
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    while (curr){
        if ((prev) && (prev->val == curr->val)){
            prev->next = curr->next;
        }
        else{
            prev = curr; // 전진
        }
        curr = curr->next;
    }
    return head;
}

struct ListNode* list_to_linked_list(int numlist[], int size) {
    if (size == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = numlist[0];
    head->next = NULL;

    struct ListNode* curr = head;

    for (int i = 1; i < size; i++) {
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->val = numlist[i];
        curr->next->next = NULL;
        curr = curr->next;
    }

    return head;
}

void print_linked_list(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    int numlist1[] = {1, 1, 2};
    int numlist2[] = {1,1,2,3,3};
    struct ListNode* head1 = list_to_linked_list(numlist1, 3);
    struct ListNode* head2 = list_to_linked_list(numlist2, 5);
    print_linked_list(deleteDuplicates(head1));
    print_linked_list(deleteDuplicates(head2));
}