#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string board[N];
    for (int i=0; i<N; i++){
        cin >> board[i];
    }
    int vis[N][N]={};

    int cnt = 0;
    vector<int> sizes;
    queue<pair<int, int>> Q;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (board[i][j] == '1' && vis[i][j] == 0){
                cnt++;
                vis[i][j] = cnt;
                Q.push({i, j});
                int size = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    
                    for (int d=0; d<4; d++){
                        int px = cur.X + dx[d];
                        int py = cur.Y + dy[d];
                        if (px < 0 || px >= N || py < 0 || py >= N) continue;
                        if (board[px][py] == '0' || vis[px][py] > 0) continue;
                        vis[px][py] = cnt;
                        size++;
                        Q.push({px, py});
                    }
                }
                sizes.push_back(size);
            }
        }
    }
    cout << cnt << '\n';
    sort(sizes.begin(), sizes.end());
    for (int i=0; i<sizes.size(); i++){
        cout << sizes[i] << '\n';
    }

    
}