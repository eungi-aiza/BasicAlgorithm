#include <iostream>
// #include <queue>
using namespace std;

int q[10000000];
int head=0; 
int tail=0;

void push(int x){
    q[tail] = x;
    tail++;
}
void pop(){
    if (head != tail){
        cout << q[head] << '\n';
        head++;
    }
    else cout << -1 << '\n';
}
int front(){
    if (head != tail) return q[head];
    else return -1;    
}
int back(){
    if (head != tail) return q[tail-1];
    else return -1;    
}
int empty(){
    if (head == tail) return 1;
    else return 0;
}
int size(){
    if (tail-head > 0) return tail-head;
    else return 0;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    string order;
    for (int i=0; i<N; i++){
        cin >> order;
        if (order == "push"){
            int new_;
            cin >> new_;
            push(new_);
        }
        else if (order == "pop") pop();      
        else if (order == "size") cout << size() << '\n';
        else if (order == "empty") cout << empty() << '\n';
        else if (order == "front") cout << front() << '\n';
        else if (order == "back") cout << back() << '\n';
    }
}