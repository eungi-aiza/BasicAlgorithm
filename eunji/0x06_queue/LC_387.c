#include <stdio.h>

#define QUEUE_SIZE 100

typedef struct {
    char arr[QUEUE_SIZE];
    int arr2[QUEUE_SIZE];
    int frontIndex;
    int backIndex;
} Queue;

void initialize(Queue* queue) {
    queue->frontIndex = 0;
    queue->backIndex = 0;
}

int front(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->frontIndex];
}

int frontIdx(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr2[queue->frontIndex];
}

int back(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->backIndex - 1];
}

int empty(Queue* queue) {
    return queue->frontIndex == queue->backIndex;
}

int size(Queue* queue) {
    return queue->backIndex - queue->frontIndex;
}

void push(Queue* queue, char value, int length) {
    if (queue->backIndex == QUEUE_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    queue->arr[queue->backIndex] = value;
    queue->arr2[queue->backIndex] = length;
    queue->backIndex++;
}

void pop(Queue* queue) {
    if (queue->frontIndex == queue->backIndex) {
        printf("Queue is empty!\n");
        return;
    }
    queue->frontIndex++;
}

void printQueue(Queue* queue){
    printf("Queue : ");
    for (int i=queue->frontIndex; i < queue->backIndex; i++){
        printf("(%c, %d) ", queue->arr[i], queue->arr2[i]);
    }
    printf("\n");
}

int firstUniqChar(char * s){
    Queue queue;
    initialize(&queue);
    int cnt[30] = {};
    int length = 0;

    while (1){
        if (s[length] == '\0') break;
        if (cnt[s[length]-'a'] == 0){
            // printf("%c %d %d\n", s[length], s[length]-'a', length);
            push(&queue, s[length], length);
        }
        cnt[s[length]-'a'] ++;
        length ++;
    }
    // printQueue(&queue);
    while (1){
        if (empty(&queue)) break;
        char curr = front(&queue);
        if (cnt[curr-'a'] > 1){
            pop(&queue);
        }
        else if (cnt[curr-'a'] == 1){
            return frontIdx(&queue);
        }
    }
    return -1;



}

int main(){
    char s1[] = "loveleetcode";
    char s2[] = "aabb";
    // printf("%d\n", 'a'-'a');
    printf("%d\n", firstUniqChar(s1));
    printf("%d\n", firstUniqChar(s2));

    return 0;
}
