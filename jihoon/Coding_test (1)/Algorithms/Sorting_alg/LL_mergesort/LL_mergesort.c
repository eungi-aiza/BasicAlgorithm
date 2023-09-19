#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode {
    int val;
    struct LinkedNode* next;
} LinkedNode;

LinkedNode* merge_sort(LinkedNode* head);
LinkedNode* merge(LinkedNode* left, LinkedNode* right);
LinkedNode* list_to_linked_list(int arr[], int n);
void print_list(LinkedNode* head);
void free_list(LinkedNode* head);

int main() {
    int a[] = {1, 3, 2, 4, 5, 6, 7, 8};
    int b[] = {5, 3, 2, 1, 4, 0, 6, 7};

    LinkedNode* ahead = list_to_linked_list(a, sizeof(a) / sizeof(a[0]));
    LinkedNode* bhead = list_to_linked_list(b, sizeof(b) / sizeof(b[0]));

    LinkedNode* sorted_ahead = merge_sort(ahead);
    LinkedNode* sorted_bhead = merge_sort(bhead);

    print_list(sorted_ahead);
    print_list(sorted_bhead);
    
    free_list(sorted_ahead);
    free_list(sorted_bhead);

    return 0;
}

LinkedNode* merge_sort(LinkedNode* head) {
    if (!head || !head->next) {
        return head;
    }

    LinkedNode *prev = NULL, *slow = head, *fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;

    LinkedNode* left = merge_sort(head);
    LinkedNode* right = merge_sort(slow);

    return merge(left, right);
}

LinkedNode* merge(LinkedNode* left, LinkedNode* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->val > right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

LinkedNode* list_to_linked_list(int arr[], int n) {
    if (n <= 0) return NULL;
    LinkedNode* head = (LinkedNode*)malloc(sizeof(LinkedNode));
    head->val = arr[0];
    head->next = NULL;

    LinkedNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = (LinkedNode*)malloc(sizeof(LinkedNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }

    return head;
}

void print_list(LinkedNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(LinkedNode* head) {
    while (head) {
        LinkedNode* temp = head;
        head = head->next;
        free(temp);
    }
}