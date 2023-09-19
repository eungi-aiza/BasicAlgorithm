#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Define a structure to represent points
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Function to calculate the Manhattan distance between two points
int manhattanDist(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 1) {
        return 0;
    }

    vector<Point> vertices;
    for (int i = 0; i < n; i++) {
        vertices.emplace_back(points[i][0], points[i][1]);
    }

    vector<int> minHeap(n);
    vector<int> costs(n, INT_MAX);
    vector<bool> visited(n, false);

    // Initialize data structures
    for (int i = 0; i < n; i++) {
        minHeap[i] = i;
    }

    costs[0] = 0;
    int minCost = 0;

    while (true) {
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
                int dist = manhattanDist(vertices[minCostVertex], vertices[i]);
                if (dist < costs[i]) {
                    costs[i] = dist;
                }
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
