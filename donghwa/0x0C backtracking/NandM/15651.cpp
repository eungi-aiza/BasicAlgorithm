/* N과 M (3)
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1) 1부터 N까지 자연수 중에서 M개를 고른 수열
2) 같은 수를 여러 번 골라도 된다.

- 입력 : 
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
- 출력 : 
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

ex1.
- 입력 :
3 1
- 출력 :
1
2
3
ex2.
- 입력 :
4 2
- 출력 :
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4
*/

#include <stdio.h>
#include <iostream>
using namespace std;
int n,m;
int arr[10];
bool isused[10];

void func(int cur){
    if (cur == m){
        for (int i=0; i<m; i++){
            cout << arr[i] << ' ';
        } cout << '\n';
        return;
    }
    for (int i=1; i<=n; i++){
        arr[cur] = i;
        func(cur+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}