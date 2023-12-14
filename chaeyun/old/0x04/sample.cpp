
#include <iostream>
#include <list>

int main() {
    std::list<int> L = {1, 2};
    // t is pointing to the position where 1 is located
    std::list<int>::iterator t = L.begin();
    L.push_front(10); // 10, 1, 2
    
    // prints the value pointed by t, which is 1
    std::cout << *t << std::endl; 
    L.push_back(5); // 10, 1, 2, 5
    
    // insert before the position pointed to by t, which is 1, so the list becomes 10, 6, 1, 2, 5
    L.insert(t, 6);
    // move t to the next position, which is where 2 is located
    t++; 
    
    // remove the element pointed to by t, which is 2, and move t to the next element, which is 5
    t = L.erase(t); 
    
    std::cout << *t << std::endl;
    for (auto i : L) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    for (std::list<int>::iterator it = L.begin(); it != L.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}


/*
struct Node {
    struct NODE *prev, *next;
    int data;
};

// pre, nxt에 포인터 대신 배열 상의 인덱스를 저장함
// pre, nxt에 -1이 있으면 값이 앞이나 뒤에 원소가 존재하지 않음을 의미
// unused - 새로운 원소가 들어갈 수 있는 인덱스, 원소가 추가될 때 마다 하나씩 증가함
// 0 : 시작 원소로 고정 (값이 들어가지 않고 단지 시작점을 나타내기 위한 더미 노드)

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; 

fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);

void traverse() {
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << endl;
}

// 새로운 원소를 생성 -> 새 원소의 pre값에 삽입할 위치의 주소 대입
// -> 새 원소의 nxt 값에 삽입할 위치의 다음 (nxt) 값을 대입
// -> 삽입할 위치의 nxt값과 그 다음 원소의 pre값을 새 원소로 변경
// -> unused 1증가
void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)  pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused ++;
}

void erase(int addr) {
    pr = pre[addr];
    nt = nxt[addr];
    if (nxt[addr] != -1) pre[nt] = pr;
    nxt[pr] = nt;
}


*/