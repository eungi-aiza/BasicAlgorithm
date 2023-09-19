#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from the source to a given vertex
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to print the shortest path distances and paths
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\t Distance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> %d \t %d\t%d", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Array to store the shortest distances from src to each vertex
    bool sptSet[V];   // Boolean array to track vertices included in the shortest path tree
    int parent[V];    // Array to store the shortest path tree

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed distance and path array
    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 4, 3, 0, 0},
        {0, 4, 0, 0, 5, 0},
        {1, 3, 0, 0, 0, 7},
        {0, 0, 5, 0, 0, 4},
        {0, 0, 0, 7, 4, 0}
    };
    int source = 0; // Source vertex

    dijkstra(graph, source);

    return 0;
}