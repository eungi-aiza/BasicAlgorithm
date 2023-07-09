#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// void print_mat(int n, int m, int mat){
//     for (int i=0; i<n; i++){
//         for (int j=0; j<m; j++){
//             cout << mat[i][j] << ' ';
//         } cout << '\n';
//     }
// }


int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    int n, m, cnt = 0;
    cin >> n;
    cin >> m;
    int board[n][m];
    int vis[n][m] = {};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    vector<int> sizes;
    queue<pair<int, int>> Q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (vis[i][j] == 0 && board[i][j] == 1) {
                vis[i][j] = 1;
                cnt++;
                Q.push({i,j});
                int size = 1;
                while (!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    // cout << '{' << cur.X << ", " << cur.Y << '}' << '\n';
                    for (int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        // cout << "cnt : " << cnt << ", size : " << size << '\n';
                        size++;
                        Q.push({nx, ny});
                    }
                }
                sizes.push_back(size);
            }
        }
    }
    cout << cnt << '\n';
    if (sizes.empty()){
        cout << "0\n";
    }
    else {
        int max = *max_element(sizes.begin(), sizes.end());
        cout << max << '\n';
    }

}