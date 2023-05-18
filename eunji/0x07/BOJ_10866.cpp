#include <iostream>
using namespace std;

const int MX = 100000;
int head = MX;
int tail = MX;
int D[2*MX+1];

void push_front(int x){
    head --;
    D[head] = x;
}
void push_back(int x){
    D[tail] = x;
    tail ++;
}
int size(void){
    int s = tail - head;
    return s;
}
int empty(void){
    if (size() == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int front(void){
    if (empty()){
        return -1;
    }
    else {
        return D[head];
    }
}
int back(void){
    if (empty()){
        return -1;
    }
    else {
        return D[tail-1];
    }
}

int pop_front(void){
    if (front() == -1){
        return -1;
    }
    else {
        int temp = front();
        head ++;
        return temp;
    }
}

int pop_back(void){
    if (back() == -1){
        return -1;
    }
    else {
        int temp = back();
        tail --;
        return temp;
    }
}
int main(void){
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string order;
        cin >> order;
        if (order == "push_back"){
            int tar;
            cin >> tar;
            push_back(tar);
        }
        else if (order == "push_front"){
            int tar;
            cin >> tar;
            push_front(tar);
        }
        else if (order == "pop_front") cout << pop_front() << '\n';
        else if (order == "pop_back") cout << pop_back() << '\n';
        else if (order == "size") cout << size() << '\n';
        else if (order == "empty") cout << empty() << '\n';
        else if (order == "front") cout << front() << '\n';
        else if (order == "back") cout << back() << '\n';
    }
}
