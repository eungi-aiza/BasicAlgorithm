#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

// Queue definition
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function prototypes
struct Queue* createQueue();
void push(struct Queue* q, int data);
void pop(struct Queue* q);
int front(struct Queue* q);
int back(struct Queue* q);
int empty(struct Queue* q);
int size(struct Queue* q);


// Create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Push an element to the queue
void push(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
    q->size++;
}

// Pop an element from the queue
void pop(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
}

// Get the front element
int front(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

// Get the rear element
int back(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->rear->data;
}

// Check if the queue is empty
int empty(struct Queue* q) {
    return q->size == 0;
}

// Get the size of the queue
int size(struct Queue* q) {
    return q->size;
}


int main() {
    struct Queue* q = createQueue();
    
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    
    printf("Front element: %d\n", front(q));
    printf("Rear element: %d\n", back(q));
    printf("Queue size: %d\n", size(q));
    
    pop(q);
    
    printf("Front element after pop: %d\n", front(q));
    printf("Rear element after pop: %d\n", back(q));
    printf("Queue size after pop: %d\n", size(q));
    
    struct Queue* q2 = createQueue();
    printf("Pushing elements into the queue:\n");
    for (int i = 1; i <= 5; i++) {
        push(q2, i);
        printf("Pushed %d, Front: %d, Back: %d, Size: %d\n", i, front(q2), back(q2), size(q2));
    }

    printf("\nPopping elements from the queue:\n");
    while (!empty(q2)) {
        printf("Front: %d, Back: %d, Size: %d\n", front(q2), back(q2), size(q2));
        pop(q2);
    }

    printf("\nAttempt to pop from an empty queue:\n");
    pop(q2);

    return 0;
}