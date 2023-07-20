#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    while(true){
        string line;
        getline(cin, line);
        // cout << "line :" << line << '\n';
        if (line == ".") break;
        stack<char> S;
        bool check = true;
        for (auto c : line){
            if (c == '(' || c == '[') S.push(c);
            else if (c == ')'){
                if (S.empty() || S.top() != '('){
                    check=false; break;
                }
                S.pop();
            }
            else if (c == ']'){
                if (S.empty() || S.top() != '['){
                    check = false; break;
                }
                S.pop();
            }
        }
        if (!S.empty()) check=false;
        if (check) cout << "yes\n";
        else cout << "no\n";
    }
}