#include <iostream>
#define MAX_SIZE 100002
using namespace std;

int heap[MAX_SIZE];
int sz = 0;

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    return;
}

void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while (idx != 1){
        int par = idx/2;
        if(heap[par] >= heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top(){
    return heap[1];
}

void heapify(int idx){
    int lc = 2 * idx, rc = 2 * idx + 1;
    int max_child;

    if (lc > sz)
        return;

    if (rc <= sz)
        max_child = (heap[rc] > heap[lc]) ? rc : lc;
    else
        max_child = lc;

    if (heap[idx] < heap[max_child]) {
        swap(heap[idx], heap[max_child]);
        heapify(max_child);
    }
}

void pop(){
    heap[1] = heap[sz--];
    heapify(1);
}

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x == 0){
            if(sz > 0){
                cout << top() << '\n';
                pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            push(x);
        }
    }
    return 0;
}