#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 6 // Number of vertices in the graph

// Define a structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int src) {
    vector<int> dist(V, INT_MAX); // Vector to store the shortest distances from src to each vertex
    vector<bool> visited(V, false); // Vector to track visited vertices

    dist[src] = 0; // Distance from the source vertex to itself is always 0

    // Priority queue to choose the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src}); // Push the source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the minimum distance
        pq.pop();

        // If this vertex has already been visited, skip it
        if (visited[u])
            continue;

        visited[u] = true; // Mark the vertex as visited

        // Update the distance to adjacent vertices
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest path distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    vector<vector<Edge>> graph(V); // Adjacency list representation of the graph

    // Add edges and their weights to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 1});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 4});
    graph[1].push_back({3, 3});
    graph[2].push_back({1, 4});
    graph[2].push_back({4, 5});
    graph[3].push_back({0, 1});
    graph[3].push_back({1, 3});
    graph[3].push_back({5, 7});
    graph[4].push_back({2, 5});
    graph[4].push_back({5, 4});
    graph[5].push_back({3, 7});
    graph[5].push_back({4, 4});

    int source = 0; // Source vertex

    dijkstra(graph, source);

    return 0;
}
