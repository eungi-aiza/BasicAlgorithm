#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    cin >> n;
    cin >> m;
    string board[n];
    int dist[n][m];
    for (int i=0; i<n ; i++){
        cin >> board[i];
    }
    for(int i=0; i<n; i++) {
        fill(dist[i], dist[i]+m, -1);
    };
    queue<pair<int, int>> Q;
    
    Q.push({0,0});
    dist[0][0] = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        // cout << "{" << cur.X << ", " << cur.Y << "}" << '\n';
        for(int dir=0; dir<4; dir++){
            int px = cur.X + dx[dir];
            int py = cur.Y + dy[dir];
            if (px < 0 || px >= n || py < 0 || py >= m) continue;
            if (board[px][py] != '1' || dist[px][py] >= 0) continue;
            dist[px][py] = dist[cur.X][cur.Y]+1;
            Q.push({px,py});
        }
    }
    cout << dist[n-1][m-1]+1 << '\n';

}