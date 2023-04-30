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
    list<char> L(init.begin(), init.end());
    auto cursor = L.end();
    
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
