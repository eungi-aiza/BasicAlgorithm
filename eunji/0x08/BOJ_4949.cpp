#include <iostream>
#include <deque>
using namespace std;

void check(deque<char> &S, char input, string &ans){
    if (input == '(' || input =='['){
        S.push_back(input);
    }
    else if (input == ')'){
        if (S.empty()) ans = "no";
        else if (S.back() == '(') {
            S.pop_back();
        }
        else ans = "no";
    }
    else if (input == ']'){
        if (S.empty()) ans = "no";
        else if (S.back() == '[') {
            S.pop_back();
        }
        else ans = "no";
    }
    else return;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    string ans = "yes";
    deque<char> S;
    while (1){
        getline(cin, input);
        // cin >> input;
        if (input == ".") break;
        for (auto c : input){
            if (ans == "yes"){
                check(S, c, ans);
            }        
            if (c == '.') {
                if (S.empty() && ans == "yes") cout << "yes\n";
                else cout << "no\n";
                ans = "yes";
                S.clear();
            }
        }
    }
}