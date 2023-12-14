/*
BFS는 neighbor 노드들을 Queue에 저장하고 부른다. 한 level씩 확인하면서 들어감.
보통  unweighted graph에서 두 노드간의 shortest path를 구할 때 사용, 혹은 undirected grpah에서 connected components 구할 때 사용.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue for BFS
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to perform BFS on a graph represented as an adjacency list
void bfs(int graph[][MAX_NODES], int start, int n) {
    bool visited[MAX_NODES] = {false};
    struct Queue* queue = createQueue();

    visited[start] = true;
    printf("Breadth First Traversal starting from node %d: ", start);

    printf("%d ", start);
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }

    printf("\n");
}

int main() {
    int n, start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    bfs(graph, start, n);

    return 0;
}