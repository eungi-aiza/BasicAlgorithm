#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1. Sort vector of integers in ascending order
void example1() {
    vector<int> v = {5, 3, 8, 1, 2, 6};
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << endl;
}

// 2. Sort vector of integers in descending order using lambda
void example2() {
    vector<int> v = {5, 3, 8, 1, 2, 6};
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for(int i : v) cout << i << " ";
    cout << endl;
}

// 3. Sort vector of strings based on length
void example3() {
    vector<string> v = {"apple", "banana", "kiwi", "grapes"};
    sort(v.begin(), v.end(), [](const string &a, const string &b) { return a.length() < b.length(); });
    for(const string &s : v) cout << s << " ";
    cout << endl;
}

// 4. Sort vector of pairs based on the second element
void example4() {
    vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 1}};
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });
    for(const auto &p : v) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
}

// 5. Sort array of integers
void example5() {
    int arr[] = {5, 3, 8, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// 4. Sort vector of pairs based on the second element ascending.
// If they are the same, sort based on the first element descending.
void example6() {
    vector<pair<int, int>> v = {{5, 3}, {2, 3}, {7, 3}, {3, 1}, {4, 2}, {1, 2}};
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    for(const auto &p : v) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
}

int main() {
    cout << "Example 1: " << endl; example1();
    cout << "Example 2: " << endl; example2();
    cout << "Example 3: " << endl; example3();
    cout << "Example 4: " << endl; example4();
    cout << "Example 5: " << endl; example5();
    cout << "Example 6: " << endl; example5();

    return 0;
}