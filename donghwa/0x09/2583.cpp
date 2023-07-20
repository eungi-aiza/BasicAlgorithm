#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio();
    cin.tie(0);

    int M, N, K;
    cin >> M;
    cin >> N;
    cin >> K;
    int board[M][N]={};
    int vis[M][N]={};

    for (int k=0; k<K; k++){
        int x1, y1, x2, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        for (int i=M-y2; i<M-y1; i++){
            for (int j=x1; j<x2; j++){
                board[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    queue<pair<int,int>> Q;
    vector<int> sizes;

    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (board[i][j] == 0 && vis[i][j] == 0){
                cnt++;
                vis[i][j] = 1;
                Q.push({i,j});
                int size = 1;
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int d=0; d<4; d++){
                        int px = cur.X + dx[d];
                        int py = cur.Y + dy[d];
                        if (px < 0 || px >= M || py < 0 || py >= N) continue;
                        if (board[px][py] == 1 || vis[px][py] == 1) continue;
                        vis[px][py] = 1;
                        size++;
                        Q.push({px,py});
                        
                    }
                }
                sizes.push_back(size);
            }     
        }
    }
    cout << cnt << '\n';
    sort(sizes.begin(), sizes.end());
    for (int i=0; i<sizes.size(); i++){
        cout << sizes[i] << ' ';
    } cout << '\n';

}