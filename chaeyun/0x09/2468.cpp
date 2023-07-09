#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

#define X first
#define Y second

using namespace std;

int M = INT_MIN;
int n;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int arr[100][100];
int visited[100][100];

int main(){
    cin >> n;
    int answer = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
            if(M<arr[i][j]){
                M = arr[i][j];
            }
        }
    }
        
    for(int h = 0; h<=M; h++){
        queue<pair<int,int>> q;
        int safe = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j] <= h || visited[i][j] != 0) continue; // 물 높이보다 낮으면 침수되므로 조사 x + 방문했으면 조사 x
                q.push({i,j});
                safe++;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];                   
                        if(nx<0 || ny <0 || nx>=n || ny>=n) continue;
                        if(visited[nx][ny] != 0 || arr[nx][ny] <= h) continue;
                        
                        q.push({nx,ny});
                        visited[nx][ny] = 1;
                    }
                }
            
           }
        }
        if(answer <= safe){
            answer = safe;
        }      
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        
    }
    cout << answer;
    return 0;
}