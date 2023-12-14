#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* frontNode;
    Node* rearNode;
    int queueSize;
} Queue;

void initialize(Queue* queue) {
    queue->frontNode = NULL;
    queue->rearNode = NULL;
    queue->queueSize = 0;
}

int getFront(Queue* queue) {
    if (queue->frontNode == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->frontNode->data;
}

int getBack(Queue* queue) {
    if (queue->rearNode == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->rearNode->data;
}

int empty(Queue* queue) {
    return queue->frontNode == NULL;
}

int size(Queue* queue) {
    return queue->queueSize;
}

void push(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rearNode == NULL) {
        queue->frontNode = queue->rearNode = newNode;
    } else {
        queue->rearNode->next = newNode;
        queue->rearNode = newNode;
    }
    queue->queueSize++;
}

void pop(Queue* queue) {
    if (queue->frontNode == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = queue->frontNode;
    queue->frontNode = queue->frontNode->next;

    if (queue->frontNode == NULL) {
        queue->rearNode = NULL;
    }

    free(temp);
    queue->queueSize--;
}


int* adj[100001];
int sz[100001];
int vis[100001]; 
int n, m, r;
int cnt = 1;
void bfs(int v){
    vis[v] = cnt++;
    Queue q;
    initialize(&q);
    push(&q, v);
    while(!empty(&q)){
        int cur = getFront(&q); pop(&q);
        for(int i = 0; i < sz[cur]; i++){
            int nxt = adj[cur][i];
            if(vis[nxt]==0){
                vis[nxt] = cnt++;
                push(&q, nxt);
            }
        }
    }
}

int descending(const void *a, const void *b) {
    if (*(int *)a < *(int *)b) return 1;
    else if (*(int *)a > *(int *)b) return -1;
    else return 0;
}

int main(){
    scanf("%d %d %d", &n, &m, &r);
    for(int i = 0 ; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sz[a]++; sz[b]++;
        adj[a] = (int*)realloc(adj[a], sz[a]*sizeof(int)); // realloc ÁÖÀÇ
        adj[b] = (int*)realloc(adj[b], sz[b]*sizeof(int));
        adj[a][sz[a]-1] = b;
        adj[b][sz[b]-1] = a;
    }

    for(int i = 1; i <= n; i++) qsort(adj[i], sz[i], sizeof(int), descending);
    bfs(r);
    for(int i = 1; i <=n; i++){
        printf("%d\n", vis[i]);
    }
}