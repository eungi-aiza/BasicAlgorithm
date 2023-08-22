#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
bool vis[10];
void dfs(){
    stack<int> s;
    s.push(1);
    vis[1] = true;
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        cout << curr << ' ';
        for (auto nxt : adj[curr]){
            if (vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}
