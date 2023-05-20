/*
head는 가장 앞에 있는 원소의 인덱스
tail은 가장 뒤에 있는 원소의 인덱스 + 1
head, tail 초기값이 0이 아니고 MX

// Deque with Array
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX +1];
int head = MX, tail = MX;

void push_front(int x) {
        dat[--head] = x;
}

void push_back(int x) {
        dat[tail++] = x;
}

void pop_front() {
        head++;
}

void pop_back() {
        tail--;
}

int front() {
        return dat[head];
}

int back() {
        return dat[tail-1];
}

*/

// STL Deque

#include <bits/stdc++.h>
using namespace std;

int main(void) {
        deque<int> DQ;
        DQ.push_front(10); // 10
        DQ.push_back(50); // 10 50
        DQ.push_front(24); // 24 10 50
        for (auto x : DQ) cout << x << ' ';
        cout << DQ.size() << '\n'; // 3
        if (DQ.empty()) cout << "DQ is empty\n";
        else cout << "DQ is not empty\n";
        DQ.pop_front(); // 10 50
        DQ.pop_back(); // 10
        
        DQ.push_back(72); // 10 72
        DQ.push_back(12); // 10 72 12
        DQ[2] = 17; // 10 72 17
        DQ.insert(DQ.begin()+1, 33); // 10 33 72 17
        DQ.insert(DQ.begin()+4, 60); // 10 33 72 17 60
        DQ.erase(DQ.begin()+3); // 10 33 72 60
        DQ.clear(); // DQ의 모든 원소 제거
}
