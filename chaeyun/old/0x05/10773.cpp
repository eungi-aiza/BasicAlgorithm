#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> t;
    while (n--) {
        int num;
        cin >> num;
        if (num) {
            t.push(num);
        } else {
            t.pop();
        }
    }

    int sum = 0;
    while (!t.empty()) {
        sum += t.top();
        t.pop();
    }

    cout << sum << endl;
    return 0;
}
