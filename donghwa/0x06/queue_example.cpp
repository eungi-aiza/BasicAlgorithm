#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    cout << Q.size() << '\n';
    if (Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty\n";
    Q.pop();
    cout << Q.front() << '\n';
    cout << Q.back() << '\n';
    Q.push(40);
    Q.pop();
    cout << Q.front() << '\n';
}