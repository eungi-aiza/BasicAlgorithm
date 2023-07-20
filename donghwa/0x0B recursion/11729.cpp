#include <bits/stdc++.h>
using namespace std;

void hanoi(int start, int end, int n){
    if (n==1){
        cout << start << ' ' << end << '\n';
        return ;
    }
    hanoi(start, 6-start-end, n-1);
    cout << start << ' ' << end << '\n';
    hanoi(6-start-end, end, n-1);
}

int pow(int a, int b){
    int val = 1;
    while(b--){
        val *= a;
    }
    return val;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // cout << pow(2,n)-1 << '\n';
    cout << (1<<n) -1 << '\n';  // (1<<k)가 bit 연산자로 2^k 이라고 한다!!
    hanoi(1,3,n);
}