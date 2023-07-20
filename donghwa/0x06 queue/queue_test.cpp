#include <bits/stdc++.h>
using namespace std;

// 선형큐 제거된 원소의 공간을 다시 사용하기 위해서 원형큐 사용,
// 백준 문제에서는 제거 횟수가 정해져있다면 그 크기 이상의 공간을 가진 선형큐를 사용하면 됨

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail] = x;
    tail++;
    // dat[tail++] = x;
}
void pop(){
    head++;
}
int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

void test(){
    push(10); push(20); push(30);
    cout << front() << '\n'; // 10
    cout << back() << '\n'; // 30
    pop(); pop();
    push(15); push(25);
    cout << front() << '\n'; // 30
    cout << back() << '\n'; // 25
}

int main(void){
    test();
}

