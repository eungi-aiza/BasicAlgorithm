#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
int dist[10];

void bfs(){
    fill(dist, dist+10, -1);
    queue<int> q;
    q.push(1);
    dist[1]= 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for (auto nxt : adj[curr]){
            if (dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[curr]+1;
        }
    }
}
