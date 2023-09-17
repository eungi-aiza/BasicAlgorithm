/* N과 M (9)
[NOTE] unordered_set

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. 
1) N개의 자연수 중에서 M개를 고른 수열
   
- 입력 : 
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

- 출력 : 
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 
각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

ex1.
- 입력 :
3 1
4 4 2
- 출력 :
2
4

ex2.
- 입력 :
4 2
9 7 9 1
- 출력 :
1 7
1 9
7 1
7 9
9 1
9 7
9 9

ex3.
- 입력 :
4 4
1 1 1 1
- 출력 :
1 1 1 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;
int n,m;
int arr[10];
int res[10];
bool isused[10];

void func(int cur){
    if (cur == m){
        for (int i=0; i<m; i++){
            cout << res[i] << ' ';
        } cout << '\n';
        return;
    }
    for (int i=0; i<n; i++){
        if (!isused[i]){
            if (i >= 1 && arr[i-1] == arr[i] && !isused[i-1]){
                continue;
            }
            res[cur] = arr[i];
            isused[i] = 1;
            func(cur+1);
            isused[i] = 0;
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    func(0);

}