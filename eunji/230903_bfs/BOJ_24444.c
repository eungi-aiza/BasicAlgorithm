#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deg[100002];
int* adj[100002];
int idx[100002];
int vis[100002] = {};

#define MAX_SIZE 100002
struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};
struct Queue createQueue();
void push(struct Queue* q, int data);
void pop(struct Queue* q);
int front(struct Queue* q);
int empty(struct Queue* q);

struct Queue createQueue() {
    struct Queue q;
    q.front = 0;
    q.rear = -1;
    q.size = 0;
    return q;
}

void push(struct Queue* q, int data) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
    q->size++;
}

void pop(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return;
    }    
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
}

int front(struct Queue* q) {
    if (empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int empty(struct Queue* q) {
    return q->size == 0;
}

void printGraph(int v){
    // Print out the adjacency lists
    for (int i = 1; i <= v; i++) {
        printf("Adjacency list of vertex %d: ", i);
        for (int j = 0; j < idx[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(){
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0 ; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        idx[a]++; idx[b]++;
        adj[a] = (int*)realloc(adj[a], idx[a]*sizeof(int)); // realloc 주의
        adj[b] = (int*)realloc(adj[b], idx[b]*sizeof(int));
        adj[a][idx[a]-1] = b;
        adj[b][idx[b]-1] = a;
    }

    for (int i = 1; i <= N; i++) {
        int n = idx[i]; 
        qsort(adj[i], n, sizeof(adj[i][0]), compare);
    }

    int curr;
    curr = 1;
    vis[R] = curr;
    struct Queue que = createQueue();    
    push(&que, R);
    while (! empty(&que)){
        int popped = front(&que);
        pop(&que);
        for (int i = 0; i < idx[popped]; i++) {
            int nei = adj[popped][i];
            if (vis[nei] == 0){
                curr ++;
                vis[nei] = curr;
                push(&que, nei);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        free(adj[i]);
    }
    for (int i=1; i<=N; i++){
        printf("%d\n", vis[i]);
    }
    return 0;

}


