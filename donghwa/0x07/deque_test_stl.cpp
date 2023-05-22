#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> DQ;

    DQ.push_back(30);
    cout << DQ.front() << '\n';
    cout << DQ.back() << '\n';
    DQ.push_front(25);
    DQ.push_back(12);
    cout << DQ.back() << '\n';
    DQ.push_back(62);
    DQ.pop_front();
    cout << DQ.front() << '\n';
    DQ.pop_front();
    cout << DQ.back() << '\n';
}