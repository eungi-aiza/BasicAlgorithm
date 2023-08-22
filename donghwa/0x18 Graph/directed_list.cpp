#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> adj[10];
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}