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
