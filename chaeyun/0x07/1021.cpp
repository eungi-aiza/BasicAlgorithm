#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    deque<int> que;
    for (int i = 1; i <= n; i++) {
        que.push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        int idx;
        auto it = find(que.begin(), que.end(), num);
        idx = distance(que.begin(), it);
        if (idx <= que.size() / 2) {
            for (int j = 0; j < idx; j++) {
                int x = que.front();
                que.pop_front();
                que.push_back(x);
                cnt++;
            }
        }
        else {
            for (int j = 0; j < que.size() - idx; j++) {
                int x = que.back();
                que.pop_back();
                que.push_front(x);
                cnt++;
            }
        }
        que.pop_front();
    }
    cout << cnt << endl;
    return 0;
}
