// not using STL queue
// Circular queue 

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MX= 10000;
int dat[MX];
int head=0, tail=0;

void push(int x) {
    dat[tail] = x;
    if (tail == MX) tail =0;
    else tail++;
}

void pop() {
    if (head == tail)  cout << -1 << endl;
    else {
    cout << dat[head] << endl;
    if (head == MX) head = 0;
    else head ++; }
}

int size() {
    if (head <= tail) return tail - head;
    else  return tail + MX - head;
}

int empty(){
    if (head == tail) return 1;
    else return 0;
}

void front() {
    if (head == tail)  cout << -1 << endl;
    else cout << dat[head] << endl;
}

void back() {
    if (head == tail)  cout << -1 << endl;
    else cout << dat[tail-1] << endl;
}


int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();

    // push X, pop, size, front, back, empty
    while(n--) {
        string c;
        getline(cin, c);
        if (c[1] == 'u') {
            int x = stoi(c.substr(5));
            push(x);
        }
        else if (c[1] == 'o') pop();
        else if (c[0] == 's') cout << size() << '\n';
        else if (c[0] == 'e')  cout << empty() << '\n';
        else if (c[0] == 'f') front();
        else if (c[0] == 'b') back();
    }
    return 0;
}