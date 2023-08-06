#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
    int count;
}Queue;

void initQueue(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->count = 0;
}

int empty(Queue *queue){
    return queue->count == 0;
}

void push(Queue *queue, int val){
    Node *newNode = (Node *)malloc(sizeof(Node)*1);
    newNode->val = val;
    newNode->next = NULL;

    if(empty(queue)){
        queue->front = newNode;
    }
    else{
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->count++;
}

int front(Queue *queue){
    if(empty(queue)){
        printf("Error : Queue is empty\n");
        return -1;
    }
    return queue->front->val;
}

void pop(Queue* queue){
    if(empty(queue)){
        printf("Error : Queue is empty\n");
    }
    queue->front = queue->front -> next;
    queue->count--;
}

int size(Queue* queue){
    return queue->count;
}


int main(void){
    int i;
    Queue queue;
 
    initQueue(&queue);//큐 초기화
    for (i = 1; i <= 10; i++) 
    {
        push(&queue, i);
    }
    while (!empty(&queue))    // 큐가 빌 때까지 
    {
        printf("%d ", front(&queue));    //큐에서 꺼내온 값 출력
        pop(&queue);
    }
    printf("\n");
    return 0;
}