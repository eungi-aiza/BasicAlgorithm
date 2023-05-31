#include <bits/stdc++.h>
using namespace std;

char board[2300][2300]; // 3**7 = 2187

// func(n, x, y) : board[x][y] to board[x+n-1][y+n-1]에 올바르게 '*'과 ' '을 넣는 함수
void func(int n, int x, int y){
    if (n == 1){
        board[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 1 && j == 1){
                continue;
            }
            else{
                func(n / 3, x + n / 3 * i, y + n / 3 * j);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        fill(board[i], board[i]+n, ' ');
    func(n, 0, 0);
    for (int i = 0 ; i < n ; i++)
        cout << board[i] << '\n';
}

/*
 board[][]는 전역변수여서 초기 값이 전부 NULL 임.
*/