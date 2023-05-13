/* 
(1) 정의와 성질
- FIFO (First in First out)
- 원소의 추가 제거, 제일 앞뒤의 원소 확인 O(1)
- 제일 앞뒤 부분이 아닌 나머지 원소들의 확인/변경이 원칙적 불가능

(2) 구현 (배열)
// head : 가장 앞의 원소 인덱스, tail : 마지막 원소 +1
// push를 하면 tail이 증가하고 pop을 하면 head가 증가
// 배열로 구현하면 삭제가 발생할 때마다 앞쪽에 쓸모없는 공간이 생김
// -> queue에 들어갈 원소를 원형으로 바꾸자 (원형 queue)

const int MX= 1000005;
int dat[MX];
int head=0, tail=0;

// 선형 queue
void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head ++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

*/

// STL queue
# include <bits/stdc++.h>
using namespace std;

int main(void) {
    queue <int> Q;
    Q.push(10); // 10
    Q.push(20); // 10 20 
    Q.push(30); // 10 20 30
    cout << Q.size() << endl; // 3

    if (Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty]n";
    Q.pop(); // 20 30
    cout << Q.front() << endl; // 20
    cout << Q.back() << endl; // 30

    Q.push(40); // 20 30 40
    Q.pop();
    cout << Q.front() << endl;

    return 0;
}