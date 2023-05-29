// BOJ 9012

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();

    while(n--) {
        string input;
        getline(cin, input);
        stack<char> ST;
        bool flg = 0;
        
        for (auto x : input) {
            if (x == '(') ST.push(x);
            else if (x == ')') {
                if (ST.empty()) {
                    flg = 1;
                    break;}
                else if (ST.top() == '(') ST.pop();
                else {
                    flg = 1;
                    break; }
            }
        }
        if (!ST.empty()) flg = 1;
        if (flg == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}