/* 미로탐색
N×M크기의 배열로 표현되는 미로가 있다.
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
- 입력 :
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
- 출력 :
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

ex1.
- 입력 :
4 6
101111
101010
101011
111011
- 출력 :
15



*/
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