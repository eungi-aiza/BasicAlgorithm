#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root))
        return -1;
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to get the top element of the stack
int peek(struct Node* root) {
    if (isEmpty(root))
        return -1;
    return root->data;
}

// Example usage
int main() {
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("%d popped from stack.\n", pop(&root));

    printf("Top element is %d.\n", peek(root));

    return 0;
}
