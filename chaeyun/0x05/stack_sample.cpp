/* 
(1) ���ǿ� ����
- FILO (First in Last out)
- ������ �߰� ����, �ֻ���� ���� Ȯ�� O(1)
- ���� ����� �ƴ� ������ ���ҵ��� Ȯ��/������ ��Ģ�� �Ұ���

(2) ���� (�迭)
// pos : ������ ���Ұ� �߰��� �� �����ؾ� �� ��

const int MX= 1000005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

// ���� ��ġ�� �ִ� ���� �������� �ʾƵ� ��. push�� �߻��ϸ� ���� ��������Ƿ�
void pop() {
    pos --;
}

int top() {
    return dat[pos-1];
}
*/

// STL Stack
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    stack<int> S;
    S.push(10);
    S.push(20);
    S.push(30);
    cout << S.size() << endl;
    
    if (S.empty()) cout << "S is empty\n";
    else cout << "S is not empty]n";
    S.pop();
    cout << S.top() << endl;
    
    // S.empty�ε� top ȣ���ϸ� runtime error �߻���
    return 0;
}