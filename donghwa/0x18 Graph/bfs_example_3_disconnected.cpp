#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
bool vis[10];
int v = 9;

void bfs(){
    queue<int> q;
    for(int i=1; i<=v; i++){
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
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
}
