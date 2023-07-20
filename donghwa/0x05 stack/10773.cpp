#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/board/view/22716
// cin.tie(NULL)은 cin과 cout의 묶음을 풀어 줍니다. 
// 기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않습니다. 입력과 출력을 여러 번 번갈아서 반복해야 하는 경우 필수적입니다.
// ios_base::sync_with_stdio(false)는 C와 C++의 버퍼를 분리합니다. 
// 이것을 사용하면 cin/cout이 더 이상 stdin/stdout과 맞춰 줄 필요가 없으므로 속도가 빨라집니다. 단, 버퍼가 분리되었으므로 cin과 scanf, gets, getchar 등을 같이 사용하면 안 되고, cout과 printf, puts, putchar 등을 같이 사용하면 안 됩니다.

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> S;
    while (N--){
        int x;
        cin >> x;
        if (x==0 && !S.empty()){
            S.pop();
        }
        else{
            S.push(x);
        }
    }
    int sum = 0;
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }
    cout << sum << '\n';
}