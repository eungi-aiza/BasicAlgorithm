/* 영역구하기
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.

예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.

M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오
- 입력 :
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 
모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
- 출력 :
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.

ex1.
- 입력 :
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
- 출력 :
3
1 7 13
*/
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