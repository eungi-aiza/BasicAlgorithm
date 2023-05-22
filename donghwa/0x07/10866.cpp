#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    deque<int> DQ;
    while(N--){
        string cmd;
        cin >> cmd;
        if (cmd == "push_front"){
            int x; cin >> x;
            DQ.push_front(x);
        } else if (cmd == "push_back"){
            int x; cin >> x;
            DQ.push_back(x);
        } else if (cmd == "pop_front"){
            if (DQ.size() > 0){
                cout << DQ.front() << '\n';
                DQ.pop_front();
            } else cout << -1 << '\n';
        } else if (cmd == "pop_back"){
            if (DQ.size() > 0){
                cout << DQ.back() << '\n';
                DQ.pop_back();
            } else cout << -1 << '\n';
        } else if (cmd == "size") cout << DQ.size() << '\n';
        else if (cmd == "empty") cout << DQ.empty() << '\n';
        else if (cmd == "front")
            if (DQ.size() > 0) cout << DQ.front() << '\n';
            else cout << -1 << '\n';
        else if (cmd == "back"){
            if (DQ.size() > 0){
                cout << DQ.back() << '\n';
            } else cout << -1 << '\n';
        }
        
    }
}