#include<bits/stdc++.h>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 1;

void dfs(int t) {
    visited[t] = cnt;
    sort(graph[t].begin(), graph[t].end());
    for(int i: graph[t]) {
        if(visited[i] == 0) {
            cnt++;
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = cnt;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int nei : graph[v]) {
            if (visited[nei] == 0) {
                q.push(nei);
                cnt++;
                visited[nei] = cnt;
            }
        }
    }
}

void bfs_noqueue(int start) {
    vector<int> bfs_list; // This vector will simulate our queue
    bfs_list.push_back(start);
    visited[start] = cnt;

    int idx = 0; // This is similar to the front of the queue
    while (idx < bfs_list.size()) {
        int v = bfs_list[idx];
        idx++;

        for (int nei : graph[v]) {
            if (visited[nei] == 0) {
                bfs_list.push_back(nei);
                cnt++;
                visited[nei] = cnt;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // For faster I/O
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    graph.resize(N+1);
    visited.resize(N+1, 0);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);  // bidirectional edge
        graph[b].push_back(a);  // bidirectional edge
    }

    dfs(R);

    for(int i = 1; i <= N; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}
