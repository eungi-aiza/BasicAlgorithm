#include <iostream>
#include <deque>
using namespace std;


bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미


int bfs(int* board, int* vis, int sx, int sy, int N, int M){
   int size = 0;
   deque<pair<int, int>> D;
   D.push_back({sx, sy});
   while (! D.empty()){
    pair<int, int> curr = D.front();
    D.pop_front();
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
        int nx = curr.first + dx[dir];
        int ny = curr.second + dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
        vis[nx][ny] = 1;
        size ++;
        D.push_back({nx, ny});
    }
   }
   return size;
}



int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);


}