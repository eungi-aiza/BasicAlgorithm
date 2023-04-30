/*
1st trial : 컴파일에러 (변수선언하고 ; 안붙임, && 써야 하는데 and... 바보
2nd trial : 커서 왼쪽 얘를 지워야 하는데 오른쪽 지우는 코드 짜버림
3rd trial : cin.ignore() 붙이니 잘 돌아감

추가 : 
- list<char> L 안에 string 집어넣는 방식이 push_back 말고도 iterator로 돌리는 방법도 있고
- auto cursor 외에도 iterator의 자료형 지정해주는 방식도 있음 (단 자료형이 명확할 경우만 가능)
- 사실 어느 경우든 메모리 할당 변화에는 영향 X (just same meaning different notation ㅇㅇ..)
*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string init;
    cin >> init;
    cin >> n;
    cin.ignore();
    list<char> L;

    // option 2 : list<char> L(init.begin(), init.end());
    for (auto c : init) {
        L.push_back(c);
    }

    // option 2 : auto cursor = L.end();
    list<char>::iterator cursor = L.end();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s[0] == 'L' && cursor != L.begin()) {
            cursor--;
        } else if (s[0] == 'D' && cursor != L.end()) {
            cursor++;
        } else if (s[0] == 'B' && cursor != L.begin()) {
            cursor--;
            cursor = L.erase(cursor);
        } else if (s[0] == 'P') {
            L.insert(cursor, s[2]);
        }
    }

    for (auto c : L) {
        cout << c;
    }
    return 0;
}
