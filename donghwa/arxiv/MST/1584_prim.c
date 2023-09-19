#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent points
struct Point {
    int x, y;
};

// Function to calculate the Manhattan distance between two points
int manhattanDist(struct Point p1, struct Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    if (n <= 1) {
        return 0;
    }

    struct Point* vertices = (struct Point*)malloc(n * sizeof(struct Point));
    for (int i = 0; i < n; i++) {
        vertices[i].x = points[i][0];
        vertices[i].y = points[i][1];
    }

    int* minHeap = (int*)malloc(n * sizeof(int));
    int* costs = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)malloc(n * sizeof(bool));

    // Initialize data structures
    for (int i = 0; i < n; i++) {
        minHeap[i] = i;
        costs[i] = INT_MAX;
        visited[i] = false;
    }

    costs[0] = 0;
    int minCost = 0;

    while (1) {
        int minCostVertex = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (minCostVertex == -1 || costs[i] < costs[minCostVertex])) {
                minCostVertex = i;
            }
        }

        if (minCostVertex == -1) {
            break; // All vertices are visited
        }

        visited[minCostVertex] = true;
        minCost += costs[minCostVertex];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
