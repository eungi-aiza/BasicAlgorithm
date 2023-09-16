#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_V 100  // Maximum number of vertices
#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
      if (dist[i] >= INF) printf("%d \t %d\n", i, -1);
      else printf("%d \t %d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices
void dijkstra(int graph[MAX_V][MAX_V], int src, int V) {
    int dist[V];       // The output array to store the shortest distance from the source
    bool sptSet[V];    // A boolean array to represent whether a vertex is included in the shortest path tree

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }

    // Distance of the source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        // Mark the selected vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    // int V;  // Number of vertices
    // printf("Enter the number of vertices: ");
    // scanf("%d", &V);

    // int graph[MAX_V][MAX_V];  // The graph represented as an adjacency matrix

    // Input the adjacency matrix representing the graph
    // printf("Enter the adjacency matrix:\n");
    // for (int i = 0; i < V; i++) {
    //     for (int j = 0; j < V; j++) {
    //         scanf("%d", &graph[i][j]);
    //     }
    // }


    int V = 6; // Number of vertices
    int graph[MAX_V][MAX_V] = {
        {0, 2, 5, 6, 0, 0},
        {0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 2, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 4, 0, 3, 0}
    };

    int src=0;  // Source vertex
    // printf("Enter the source vertex: ");
    // scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}
