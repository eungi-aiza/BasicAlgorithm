#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos] = x;
    pos++;
    // dat[pos++] = x;
}

int pop(){
    pos--;
    int val = dat[pos];
    dat[pos] = -1;
    return val;
    // pos--;
}
int top(){
    int tmp = pos-1;
    return dat[tmp];
    // return dat[pos-1];
}

void test(){
    push(10);
    push(20);
    push(30);
    for (int i=0; i<pos; i++){
        cout << dat[i] << " ";
    }
    cout << endl;
    cout << "top :" << top() << endl;
    int pop_val = pop();
    cout << "pop value :" << pop_val << endl;
    for (int i=0; i<pos; i++){
        cout << dat[i] << " ";
    }
    cout << endl;

    push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void){
    test();
}
