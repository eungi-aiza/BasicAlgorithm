/* 덱
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

- 입력 :
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

- 출력 :
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


ex1.
- 입력 :
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front
- 출력 :
2
1
2
0
2
1
-1
0
1
-1
0
3
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    deque<int> DQ;
    while(N--){
        string cmd;
        cin >> cmd;
        if (cmd == "push_front"){
            int x; cin >> x;
            DQ.push_front(x);
        } else if (cmd == "push_back"){
            int x; cin >> x;
            DQ.push_back(x);
        } else if (cmd == "pop_front"){
            if (DQ.size() > 0){
                cout << DQ.front() << '\n';
                DQ.pop_front();
            } else cout << -1 << '\n';
        } else if (cmd == "pop_back"){
            if (DQ.size() > 0){
                cout << DQ.back() << '\n';
                DQ.pop_back();
            } else cout << -1 << '\n';
        } else if (cmd == "size") cout << DQ.size() << '\n';
        else if (cmd == "empty") cout << DQ.empty() << '\n';
        else if (cmd == "front")
            if (DQ.size() > 0) cout << DQ.front() << '\n';
            else cout << -1 << '\n';
        else if (cmd == "back"){
            if (DQ.size() > 0){
                cout << DQ.back() << '\n';
            } else cout << -1 << '\n';
        }
        
    }
}