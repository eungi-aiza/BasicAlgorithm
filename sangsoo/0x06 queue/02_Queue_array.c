#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024


typedef struct Queue{
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
}Queue;

void initQueue(Queue *queue){
    queue->front = 0;
    queue->rear = -1; // setting it to -1 means the queue is empty
    queue->count = 0;
}

int empty(Queue *queue){
    return queue->count == 0;
}

int full(Queue* queue){
    return queue->count == MAX_SIZE;
}

void push(Queue *queue, int val){
    if(full(queue)){
        printf("Error: Queue is full");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = val;
    queue->count++;
}
int back(Queue *queue) {
    if(empty(queue)){
        return -1;
    }
    return queue->data[queue->rear];
}
int front(Queue *queue){
    if(empty(queue)){
        return -1;
    }
    return queue->data[queue->front];
}

void pop(Queue* queue){
    if(empty(queue)){
        printf("-1\n");
    }
    queue->front = (queue->front+1) %MAX_SIZE;
    queue->count--;
}
int size(Queue* queue){
    return queue->count;
}

int n;

int main(void){
    Queue q;
    initQueue(&q);
    scanf("%d",&n);
    while(n--){
        char op[10];
        scanf("%s", &op);
        if (op == "push"){
            int num;
            scanf("%d", &num);
            push(&q, num);
        }
        else if (op == "front"){
            printf("%d\n", front(&q));
        }
        else if (op == "back"){
            printf("%d\n", back(&q));
        }
        else if (op == "pop"){
            printf("%d\n", front(&q));
            pop(&q);
        }
        else if (op == "empty"){
            printf("%d\n", empty(&q));
        }
    }
}