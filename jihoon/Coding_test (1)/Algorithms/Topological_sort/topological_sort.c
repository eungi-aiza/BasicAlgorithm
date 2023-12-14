#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V; // Number of vertices
    struct Node** adjList; // Adjacency list
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node* stack) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            topologicalSortUtil(graph, adjVertex, visited, stack);
        }
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = stack->next;
    stack->next = newNode;
}

void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int visited[V];
    struct Node* stack = (struct Node*)malloc(sizeof(struct Node));
    stack->next = NULL;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    printf("Topological Sort:\n");

    while (stack->next != NULL) {
        printf("%d ", stack->next->data);
        struct Node* temp = stack->next;
        stack->next = stack->next->next;
        free(temp);
    }

    printf("\n");
}

int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
