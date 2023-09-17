#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a GNode structure
typedef struct GNode {
    char id[3];
    char color; // 'W', 'B'
    int distance;
    struct GNode* parent;
} GNode;

// Define a queue data structure
typedef struct QueueNode {
    GNode* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, GNode* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

GNode* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    
    QueueNode* temp = q->front;
    GNode* data = temp->data;
    q->front = q->front->next;
    free(temp);
    
    return data;
}

// Function to perform level partition
void level_partition(GNode* G[], int GSize, GNode* start) {
    char result[100][100]; // Assuming a maximum of 100 substrings with 100 characters each.
    int result_count = 0;
    Queue q;
    initQueue(&q);
    
    // Initialize the start node
    start->color = 'B';
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int levelSize = 0;
        QueueNode* levelHead = q.front;
        
        // Count the nodes in the current level
        while (levelHead != NULL) {
            levelSize++;
            levelHead = levelHead->next;
        }
        
        GNode* level[levelSize];
        
        // Process nodes in the current level
        for (int i = 0; i < levelSize; i++) {
            GNode* u = dequeue(&q);
            level[i] = u;
            
            for (int j = 0; j < GSize; j++) {
                GNode* v = G[j];
                
                if (v->color == 'W') {
                    v->color = 'B';
                    enqueue(&q, v);
                }
            }
        }
        
        // Store the current level in the result
        for (int i = 0; i < levelSize; i++) {
            strcpy(result[result_count], level[i]->id);
            result_count++;
        }
    }
    
    // Print the result
    for (int i = 0; i < result_count; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");
}

int main() {
    GNode r = {"r", 'W', 0, NULL};
    GNode s = {"s", 'W', 0, NULL};
    GNode t = {"t", 'W', 0, NULL};
    GNode u = {"u", 'W', 0, NULL};
    GNode v = {"v", 'W', 0, NULL};
    GNode w = {"w", 'W', 0, NULL};
    GNode x = {"x", 'W', 0, NULL};
    GNode y = {"y", 'W', 0, NULL};
    
    GNode* G[] = {&r, &s, &t, &u, &v, &w, &x, &y};
    int GSize = sizeof(G) / sizeof(G[0]);

    // Build the graph edges (adjacency list)
    GNode* edges[][4] = {
        {&s, &v, NULL},
        {&r, &w, NULL},
        {&w, &x, &u},
        {&t, &x, &y},
        {&r, NULL},
        {&s, &t, &x},
        {&w, &t, &u, &y},
        {&x, &u, NULL}
    };

    for (int i = 0; i < GSize; i++) {
        G[i]->color = 'W';
    }

    level_partition(G, GSize, &s);

    return 0;
}
