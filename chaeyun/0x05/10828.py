#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    stack<int> S;
    
    // push X, pop, size, top, empty
    while(n--) {
        string c;
        getline(cin, c);
        if (c[1] == 'u') {
            int x = stoi(c.substr(5));
            S.push(x);
        }
        else if (c[0] == 'p') {
            if (S.empty()) cout << -1 << endl;
            else {
                cout << S.top() << endl;
                S.pop();
            }    
        }
        else if (c[0] == 's') cout << S.size() << endl;
        else if (c[0] == 'e') cout << (int)S.empty() << endl;
        else {
            if (S.empty()) cout << -1 << endl;
            else cout << S.top() << endl;
        }
    }
    return 0;
}
