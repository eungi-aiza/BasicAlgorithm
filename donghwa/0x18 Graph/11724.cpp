/* 연결요소의 개수
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

- 입력 :
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
- 출력 :
첫째 줄에 연결 요소의 개수를 출력한다.

ex1.
- 입력 :
6 5
1 2
2 5
5 1
3 4
4 6
- 출력 :
2
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> adj[1005];
    int vis[1005];

    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> q;
    int cnt = 0;
    fill(vis, vis+n, 0);
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        cnt += 1;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur]){
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << cnt << '\n';
    
    
}