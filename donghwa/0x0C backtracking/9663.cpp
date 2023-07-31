#include <bits/stdc++.h>
using namespace std;

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