#include <bits/stdc++.h>
using namespace std;

const int MX = 10;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    if (head != tail) head++;
}
void pop_back(){
    if (tail != head) tail--;
}
int front(){
    if (head != tail){
        return dat[head];
    } else return -1;
}
int back(){
    if (head != tail){
        return dat[tail-1];
    } else return -1;
}

void print_deque(){
    for(int i=head;i<tail;i++){
        cout << dat[i] << ' ';
    } cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    cin >> M;
    int size = N;
    while(N--){
        push_front(N+1);
    }
    print_deque();
    int cnt = 0;
    while(M--){
        int num;
        cin >> num;
        cout << "num :" << num << '\n';
        if (front() == num){
            pop_front();
            size--;
        } else {
            int trg = 0;
            cout << "before get trg :" << '\n';
            print_deque();
            while(dat[head+trg] != num){
                trg++;
            }
            cout << "trg :" << trg << '\n';
            cout << "size :" << size << '\n';
            if (trg <= size-trg){
                cout << "trg-head :" << trg-head << '\n';
                for(int i=0; i<trg-head; i++){
                    push_back(front());
                    pop_front();
                    cnt++;
                    cout << "left cnt :" << cnt << '\n';
                }
                print_deque();
            } else {
                for(int i=0; i<tail-trg; i++){
                    push_front(back());
                    pop_back();
                    cnt++;
                    cout << "right cnt :" << cnt << '\n';
                }
                print_deque();
            }
        }
        cout << endl;
    }
    cout << cnt << '\n';
}