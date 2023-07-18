#include <stdio.h>

#define X first
#define Y second 
#define SIZE 502
#define QUEUE_SIZE 502*502
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct pair {
    int first;
    int second;
} pair;

int board[SIZE][SIZE];
int vis[SIZE][SIZE];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

pair dequeue() {
    return queue[++front];
}

void enqueue(pair p) {
    queue[++rear] = p;
}

int isEmpty() {
    return rear == front;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < m ; j++)
            scanf("%d", &board[i][j]);
    int mx = 0; 
    int num = 0; 
    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < m ; j++){
            if(board[i][j] == 0 || vis[i][j]) continue; 
            num++; 
            front = -1;
            rear = -1;
            pair p = {i, j};
            vis[i][j] = 1;
            enqueue(p);
            int area = 0; 
            while (!isEmpty()){
                area++; 
                pair cur = dequeue();
                for(int dir = 0; dir <4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0||nx >= n || ny < 0||ny >= m) continue; 
                    if (vis[nx][ny] || board[nx][ny] != 1) continue; 
                    vis[nx][ny] = 1;
                    pair new_p = {nx, ny};
                    enqueue(new_p);
                }
            }
            mx = max(mx, area); 
        }
    }
    printf("%d\n%d", num, mx);
    return 0;
}
