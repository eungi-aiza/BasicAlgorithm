#include <bits/stdc++.h>
using namespace std;
// stack 영역 메모리를 작게 걸린 문제라면 이렇게 풀면 안됨. 재귀는 stack 메모리를 많이 쓰기 때문. 재귀 대신 stack을 써라! 

vector <int> adj[10];
bool vis[10];
void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}