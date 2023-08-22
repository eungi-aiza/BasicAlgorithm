#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
bool vis[10];
void bfs(){
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for (auto nxt : adj[curr]){
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}
