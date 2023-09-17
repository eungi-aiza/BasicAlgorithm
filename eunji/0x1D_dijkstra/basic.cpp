#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define X first
#define Y second
#define INF (0x3f3f3f3f)


vector<pair<int, int>> adj[20005]; // 각 정점의 인접 리스트
int fix[20005] = {}; // 정점이 처리되었는지 여부
int d[20005]; // 각 정점까지의 최소 거리
int V = 10; // 정점의 수

void dijkstra_naive(int st) {
    fill(d, d + V + 1, INF); // 모든 정점까지의 거리를 무한대로 초기화
    d[st] = 0; // 출발 정점까지의 거리를 0으로 설정
    
    while (1) {
        int idx = -1;
        
        // 아직 처리되지 않은 정점 중에서 가장 작은 거리를 가진 정점을 찾습니다.
        for (int i = 1; i <= V; i++) {
            if (fix[i]) continue;
            if (idx == -1) idx = i;
            else if (d[i] < d[idx]) idx = i;
        }
        
        // 정점을 찾지 못하거나 가장 작은 거리가 무한대인 경우 루프를 종료
        if (idx == -1 || d[idx] == INF) break;
        
        // 고른 정점 처리 표시
        fix[idx] = 1;
        
        // 고른 정점을 통해 이웃 정점까지의 거리를 업데이트
        for (auto nxt : adj[idx]) {
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
        }
    }
}

int main() {
    // Example usage:
    V = 6; // Update the number of vertices
    adj[1].push_back({2, 2}); // Edge from vertex 1 to vertex 2 with weight 2
    adj[1].push_back({5, 3}); // Edge from vertex 1 to vertex 3 with weight 5
    adj[2].push_back({4, 4}); // Edge from vertex 2 to vertex 4 with weight 4
    // adj[3].push_back({4, 6}); // Edge from vertex 5 to vertex 6 with weight 1
    adj[6].push_back({4, 3}); // Edge from vertex 5 to vertex 6 with weight 1
    adj[4].push_back({3, 3}); // Edge from vertex 4 to vertex 3 with weight 3
    adj[4].push_back({2, 5}); // Edge from vertex 5 to vertex 4 with weight 2
    // adj[5].push_back({3, 6}); // Edge from vertex 6 to vertex 3 with weight 4
    adj[6].push_back({3, 5}); // Edge from vertex 6 to vertex 3 with weight 4

    int startVertex = 1; // Set the starting vertex
    dijkstra_naive(startVertex);

    // Print the shortest distances from the starting vertex to all other vertices
    cout << "Shortest distances from vertex " << startVertex << ":" << endl;
    for (int i = 1; i <= V; i++) {
        if (d[i] >= INF) cout << "Vertex " << i << ": " << -1 << endl;
        else cout << "Vertex " << i << ": " << d[i] << endl;
    }

    return 0;
}

/*
Shortest distances from vertex 1:
Vertex 1: 0
Vertex 2: 2
Vertex 3: 5
Vertex 4: 6
Vertex 5: 8
Vertex 6: -1
*/