/* 
(1) ���ǿ� ����
- FIFO (First in First out)
- ������ �߰� ����, ���� �յ��� ���� Ȯ�� O(1)
- ���� �յ� �κ��� �ƴ� ������ ���ҵ��� Ȯ��/������ ��Ģ�� �Ұ���

(2) ���� (�迭)
// head : ���� ���� ���� �ε���, tail : ������ ���� +1
// push�� �ϸ� tail�� �����ϰ� pop�� �ϸ� head�� ����
// �迭�� �����ϸ� ������ �߻��� ������ ���ʿ� ������� ������ ����
// -> queue�� �� ���Ҹ� �������� �ٲ��� (���� queue)

const int MX= 1000005;
int dat[MX];
int head=0, tail=0;

// ���� queue
void push(int x) {
    dat[tail++] = x;
}

void pop() {
    head ++;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

*/

// STL queue
# include <bits/stdc++.h>
using namespace std;

int main(void) {
    queue <int> Q;
    Q.push(10); // 10
    Q.push(20); // 10 20 
    Q.push(30); // 10 20 30
    cout << Q.size() << endl; // 3

    if (Q.empty()) cout << "Q is empty\n";
    else cout << "Q is not empty]n";
    Q.pop(); // 20 30
    cout << Q.front() << endl; // 20
    cout << Q.back() << endl; // 30

    Q.push(40); // 20 30 40
    Q.pop();
    cout << Q.front() << endl;

    return 0;
}