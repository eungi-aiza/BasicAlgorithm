#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent edges
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a disjoint-set (Union-Find)
class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

// Compare function for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    // Create an array of edges
    int numEdges = n * (n - 1) / 2;
    vector<Edge> edges(numEdges);
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
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Initialize Union-Find data structure
    UnionFind uf(n);
    
    int minCost = 0;
    int edgesAdded = 0;
    
    for (int i = 0; i < numEdges; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        
        if (uf.find(src) != uf.find(dest)) {
            uf.unionSets(src, dest);
            minCost += weight;
            edgesAdded++;
            if (edgesAdded == n - 1) {
                break;  // Minimum spanning tree is complete
            }
        }
    }
    
    return minCost;
}

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    
    int result = minCostConnectPoints(points);
    cout << "Minimum cost: " << result << endl;  // Output should be 20
    
    return 0;
}
