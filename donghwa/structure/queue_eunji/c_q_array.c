#include <stdio.h>
#include <stdlib.h>

// Queue definition
#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function prototypes
struct Queue createQueue();
void push(struct Queue* q, int data);
void pop(struct Queue* q);
int front(struct Queue* q);
int back(struct Queue* q);
int empty(struct Queue* q);
int size(struct Queue* q);

// Create a new queue
struct Queue createQueue() {
    struct Queue q;
    q.front = 0;
    q.rear = -1;
    q.size = 0;
    return q;
}

// Push an element to the queue
void push(struct Queue* q, int data) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
    q->size++;
}

// Pop an element from the queue
void pop(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
}

// Get the front element
int front(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

// Get the rear element
int back(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->rear];
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
    struct Queue q = createQueue();    
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    push(&q, 4);
    
    printf("Front element: %d\n", front(&q));
    printf("Rear element: %d\n", back(&q));
    printf("Queue size: %d\n", size(&q));
    
    pop(&q);
    
    printf("Front element after pop: %d\n", front(&q));
    printf("Rear element after pop: %d\n", back(&q));
    printf("Queue size after pop: %d\n", size(&q));

    struct Queue queue = createQueue();    
    printf("Pushing elements into the queue:\n");
    for (int i = 1; i <= 5; i++) {
        push(&queue, i);
        printf("Pushed %d, Front: %d, Back: %d, Size: %d\n", i, front(&queue), back(&queue), size(&queue));
    }

    printf("\nPopping elements from the queue:\n");
    while (!empty(&queue)) {
        printf("Front: %d, Back: %d, Size: %d\n", front(&queue), back(&queue), size(&queue));
        pop(&queue);
    }

    printf("\nAttempt to pop from an empty queue:\n");
    pop(&queue);

    return 0;
}