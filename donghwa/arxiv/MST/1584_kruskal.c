/*
1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane,
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] 
is the manhattan distance between them: |xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.

ex1.
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
 
ex2.
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent edges
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a disjoint-set (Union-Find)
struct UnionFind {
    int *parent;
};

// Create a Union-Find data structure with 'n' elements
struct UnionFind* createUnionFind(int n) {
    struct UnionFind* uf = (struct UnionFind*)malloc(sizeof(struct UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
    }
    return uf;
}

// Find the root of a set to which 'x' belongs
int find(struct UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

// Union two sets
void unionSets(struct UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);
    if (rootX != rootY) {
        uf->parent[rootX] = rootY;
    }
}

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    // Create an array of edges
    int numEdges = n * (n - 1) / 2;
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    int edgeIndex = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int manhattanDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            edges[edgeIndex].src = i;
            edges[edgeIndex].dest = j;
            edges[edgeIndex].weight = manhattanDist;
            edgeIndex++;
        }
    }
    
    // Sort edges by weight
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);
    
    // Initialize Union-Find data structure
    struct UnionFind* uf = createUnionFind(n);
    
    int minCost = 0;
    int edgesAdded = 0;
    
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        
        if (find(uf, src) != find(uf, dest)) {
            unionSets(uf, src, dest);
            minCost += weight;
            edgesAdded++;
            if (edgesAdded == n - 1) {
                break;  // Minimum spanning tree is complete
            }
        }
    }
    
    free(uf->parent);
    free(uf);
    free(edges);
    
    return minCost;
}

int main() {
    int points[][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int pointsSize = sizeof(points) / sizeof(points[0]);
    int pointsColSize = sizeof(points[0]) / sizeof(points[0][0]);
    
    int result = minCostConnectPoints(points, pointsSize, &pointsColSize);
    printf("Minimum cost: %d\n", result);  // Output should be 20
    
    return 0;
}
