#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void permute(vector<char>& a, int l, int r, vector<string>& ans) {
    if (l == r) {
        string permutation;
        for (char c : a) {
            permutation += c;
        }
        auto exists = find(ans.begin(), ans.end(), permutation);
        if (exists == ans.end())
            ans.push_back(permutation);
    } else {
        for (int i = l; i < r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r, ans);
            swap(a[l], a[i]);  // backtrack
        }
    }
}

int main() {
    string str = "abb";
    int n = str.size();
    vector<char> s_vec;
    for (auto& f : str) {
        s_vec.push_back(f);
    }
    vector<string> ans;
    permute(s_vec, 0, n, ans);
    for (const string& permutation : ans) {
        cout << permutation << endl;
    }
    return 0;
}