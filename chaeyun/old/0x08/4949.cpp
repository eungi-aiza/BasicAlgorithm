// 수식의 괄호쌍 : 주어진 괄호 문자열이 올바른지 판단하는 문제
// 문자열을 앞에서부터 읽어나갈 때, 닫는 괄호는 남아있는 괄호 중에서 가장 최근에 들어온 여는 괄호와 짝을 지어 없애버리는 방법
/*
step
1- 여는 괄호가 나오면 스택에 추가
2- 닫는 괄호가 나온다면
    - 스택이 비어있으면 올바르지 않음
    - 스택의 top이 짝이 맞지 않는 괄호라면 올바르지 않음
    - 스택의 top이 짝이 맞는다면 pop
3- 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 오류, 남아있지 않으면 올바른 괄호 쌍
*/


// BOJ 4949

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        string input;
        getline(cin, input);
        if (input == ".") break;
        stack<char> ST;
        bool flg = 0;
        
        for (auto x : input) {
            if ((x == '(') || (x == '[')) ST.push(x);
            else if ((x == ')') || (x == ']')) {
                if (ST.empty()) {
                    flg = 1;
                    break;}
                else if ((x == ')') && (ST.top() == '(')) ST.pop();
                else if ((x == ']') && (ST.top() == '[')) ST.pop();
                else {
                    flg = 1;
                    break; }
            }
        }
        if (!ST.empty()) flg = 1;
        if (flg == 0) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}