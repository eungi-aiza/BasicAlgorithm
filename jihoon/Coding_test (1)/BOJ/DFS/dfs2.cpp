#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m, r;
unordered_map<int, vector<int>> adj;
int vis[100001];
int cnt = 1;

void dfs(int v){
    if(vis[v] == 0){
        vis[v] = cnt++;
        for(auto nxt : adj[v]){
            if(vis[nxt] == 0){
                dfs(nxt);
            }
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1 ; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    dfs(r);
    for(int i = 1; i <= n; i++)
        cout << vis[i] << '\n';
}