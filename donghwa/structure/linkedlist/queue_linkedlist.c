#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int size;
};

// Function to initialize a LinkedList
void LinkedList_init(struct LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Function to get the front element of the linked list
int LinkedList_front(struct LinkedList* list) {
    if (list->head != NULL) {
        return list->head->data;
    } else {
        printf("List is empty!\n");
        return -1;
    }
}

// Function to get the back element of the linked list
int LinkedList_back(struct LinkedList* list) {
    if (list->tail != NULL) {
        return list->tail->data;
    } else {
        printf("List is empty!\n");
        return -1;
    }
}

// Function to get the size of the linked list
int LinkedList_size(struct LinkedList* list) {
    return list->size;
}

// Function to check if the linked list is empty
int LinkedList_empty(struct LinkedList* list) {
    return (list->size == 0);
}

// Function to push an element to the back of the linked list
void LinkedList_push(struct LinkedList* list, int x) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    tmp->data = x;
    tmp->next = NULL;

    if (list->tail == NULL) {
        list->head = tmp;
        list->tail = tmp;
    } else {
        list->tail->next = tmp;
        list->tail = tmp;
    }

    list->size++;
}

// Function to pop the front element from the linked list
void LinkedList_pop(struct LinkedList* list) {
    if (list->size > 0) {
        struct Node* tmp = list->head->next;
        free(list->head);
        list->head = tmp;
        list->size--;

        if (list->size == 0) {
            list->tail = NULL;
        }
    }
}

int main() {
    struct LinkedList list;
    LinkedList_init(&list);

    LinkedList_push(&list, 1);
    LinkedList_push(&list, 2);
    LinkedList_push(&list, 3);

    printf("Front: %d\n", LinkedList_front(&list));
    printf("Back: %d\n", LinkedList_back(&list));

    LinkedList_pop(&list);
    printf("Front after pop: %d\n", LinkedList_front(&list));

    // Clean up the memory
    while (!LinkedList_empty(&list)) {
        LinkedList_pop(&list);
    }

    return 0;
}
