
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

// pre, nxt�� ������ ��� �迭 ���� �ε����� ������
// pre, nxt�� -1�� ������ ���� ���̳� �ڿ� ���Ұ� �������� ������ �ǹ�
// unused - ���ο� ���Ұ� �� �� �ִ� �ε���, ���Ұ� �߰��� �� ���� �ϳ��� ������
// 0 : ���� ���ҷ� ���� (���� ���� �ʰ� ���� �������� ��Ÿ���� ���� ���� ���)

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

// ���ο� ���Ҹ� ���� -> �� ������ pre���� ������ ��ġ�� �ּ� ����
// -> �� ������ nxt ���� ������ ��ġ�� ���� (nxt) ���� ����
// -> ������ ��ġ�� nxt���� �� ���� ������ pre���� �� ���ҷ� ����
// -> unused 1����
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