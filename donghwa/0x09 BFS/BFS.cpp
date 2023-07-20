#include <bits/stdc++.h>
using namespace std;
#define X first // pair를 편하게 쓰기 위해서 first -> X로
#define Y second // second->Y로 불러옴

int board[502][502] = {...};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio();
    cin.tie(0);

    queue<pair<int,int>> Q;
    vis[0][0] = 1;
    Q.push({0,0});

    while (!Q.empty()){
        pair <int,int> cur = Q.front(); Q.pop();
        for (int i =0; i<dx.length(); i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}