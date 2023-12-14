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
int *bfs(int graph[][MAX_NODES], int start, int N) {
  int *bfs_path = (int *)malloc(N*sizeof(int));
  for (int i = 0; i < N; i++) {
    bfs_path[i] = 0;
  }
  bool visited[MAX_NODES] = {false};
  struct Queue* queue = createQueue();
  visited[start] = true;
  int j = 0;
  bfs_path[j] = start;
  printf("Breadth First Traversal starting from node %d: ", start);
  printf("%d ", start);
  enqueue(queue, start);
  while (!isEmpty(queue)) {
      int currentNode = dequeue(queue);
      // i is the neighbor
      for (int i = 0; i < N; i++) {
          if (graph[currentNode][i] && !visited[i]) {
              printf("%d ", i);
              j++;
              bfs_path[j] = i;
              visited[i] = true;
              enqueue(queue, i);
          }
      }
  }

  printf("\n");
  for (int i = 0; i < N; i++) {
    printf("%d", bfs_path[i]);
  }
  return bfs_path;
}

int main() {
  int N, M, R;
  int u, v;
  scanf("%d %d %d", &N, &M, &R);

  int graph[MAX_NODES][MAX_NODES];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  bfs(graph, R, N);

  return 0;
}