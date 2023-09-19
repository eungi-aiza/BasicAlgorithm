#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    deque <int> DQ;
    
    // push_back, push_front, pop_front, pop_back
    // size, empty, front, back
    while(n--) {
        string c;
        cin >> c;
        if (c == "push_front") {
            int val;
            cin >> val;
            DQ.push_front(val);
        }
        else if (c == "push_back") {
            int val;
            cin >> val;
            DQ.push_back(val);
        }
        else if (c == "pop_front") {
            if (DQ.empty()) cout << -1 << endl;
            else { 
                cout << DQ.front() << endl;
                DQ.pop_front();
            }
        }
        else if (c == "pop_back") {
            if (DQ.empty()) cout << -1 << endl;
            else { 
                cout << DQ.back() << endl;
                DQ.pop_back();
            }
        }
        else if (c == "size") {
            cout << DQ.size() << endl;
        }
        else if (c == "empty"){
            cout << (int)DQ.empty() << endl;
        }
        else if (c == "front") {
            if (DQ.empty()) cout << -1 << endl;
            else cout << DQ.front() << endl;
        }
       else { // back
            if (DQ.empty()) cout << -1 << endl;
            else cout << DQ.back() << endl;
        }
    }
    return 0;
}
