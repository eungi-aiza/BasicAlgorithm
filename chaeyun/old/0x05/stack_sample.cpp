/* 
(1) 정의와 성질
- FILO (First in Last out)
- 원소의 추가 제거, 최상단의 원소 확인 O(1)
- 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적 불가능

(2) 구현 (배열)
// pos : 다음의 원소가 추가될 때 삽입해야 할 곳

const int MX= 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

// 기존 위치에 있던 값은 변경하지 않아도 됨. push가 발생하면 값이 덮어씌워지므로
void pop() {
    pos --;
}

int top() {
    return dat[pos-1];
}
*/

// STL Stack
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    stack<int> S;
    S.push(10);
    S.push(20);
    S.push(30);
    cout << S.size() << endl;
    
    if (S.empty()) cout << "S is empty\n";
    else cout << "S is not empty]n";
    S.pop();
    cout << S.top() << endl;
    
    // S.empty인데 top 호출하면 runtime error 발생함
    return 0;
}