#include <bits/stdc++.h>
using namespace std;

int main(void){
    stack<int> S;
    S.push(10);
    S.push(20);
    S.push(30);
    cout << S.size() << endl; //3
    if (S.empty()) cout << "S is empty" << endl;
    else cout << "S is not empty" << endl;
    S.pop();
    cout << S.top() << endl; //20
    S.pop();
    cout << S.top() << endl; //10
    S.pop();
    if (S.empty()) cout << "S is empty" << endl;
    else cout << "S is not empty" << endl;
}