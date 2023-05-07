// endl 을 쓰는 것보다 '\n'을 쓰는것이 더 빠르다. 
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> S;
    while (N--){
        string cmd;
        cin >> cmd;
        if (cmd=="push"){
            int x; 
            cin >> x;
            S.push(x);
        } else if (cmd=="pop"){
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n'; 
                S.pop();
            }
        } else if (cmd=="size"){
            cout << S.size() << '\n';
        } else if (cmd=="empty"){
            if (S.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            if (S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
    }
}

