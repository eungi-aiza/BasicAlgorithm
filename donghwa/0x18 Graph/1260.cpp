/* DFS과 BFS
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
정점 번호는 1번부터 N번까지이다.

- 입력 :
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.
- 출력 :
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

ex1.
- 입력 :
4 5 1
1 2
1 3
1 4
2 4
3 4
- 출력 :
1 2 4 3
1 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj[1001];
bool vis[1001];

// 비재귀 DFS
void dfs(){
    stack<int> s;
    s.push(st);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for (int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][adj[cur].size()-1-i]; // 역순으로 입력
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
    cout << '\n';
}

// 재귀 DFS
void dfs_recur(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if (vis[nxt]) continue;
        dfs_recur(nxt);
    }
}

// BFS
void bfs(){
    fill(vis, vis+1001, 0);
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt : adj[cur]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }  
    cout << '\n';
}



int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    cin >> n >> m >> st;  
    
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    
    // dfs_recur(st);
    // cout << '\n';
    dfs();
    bfs();
}
