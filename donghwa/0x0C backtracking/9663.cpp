#include <bits/stdc++.h>
using namespace std;

/* N-queen
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
- 입력 : 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
- 출력 : 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

ex.
입력  :
8
출력 : 
92
*/

int cnt=0;
int n;
bool isused1[40];
bool isused2[40];
bool isused3[40];

// cur번째 행에 말을 배치할 예정
void func(int cur){
    if (cur == n){
        cnt++;
        return;
    }
    for (int k=0; k<n;k++){
        if (isused1[k] || isused2[cur+k] || isused3[cur-k+n-1]){
            continue;
        }
        isused1[k] = 1;
        isused2[cur+k] = 1;
        isused3[cur-k+n-1] = 1;
        func(cur+1);
        isused1[k] = 0;
        isused2[cur+k] = 0;
        isused3[cur-k+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt << '\n';
}