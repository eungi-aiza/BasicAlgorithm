#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

// A structure to represent a queue for topological sorting
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue* q) {
    return (q->rear == -1);
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// A function to perform topological sorting
void topologicalSort(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int inDegree[MAX_NODES] = {0};
    struct Queue queue;
    initQueue(&queue);

    // Calculate in-degrees
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    // Enqueue nodes with in-degree 0
    for (int i = 0; i < nodes; i++) {
        if (inDegree[i] == 0) {
            enqueue(&queue, i);
        }
    }

    // Perform topological sorting
    while (!isEmpty(&queue)) {
        int current = dequeue(&queue);
        printf("%d ", current);

        for (int i = 0; i < nodes; i++) {
            if (graph[current][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    enqueue(&queue, i);
                }
            }
        }
    }
}

int main() {
    int nodes = 6;
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Topological Sorting Order: ");
    topologicalSort(graph, nodes);

    return 0;
}
