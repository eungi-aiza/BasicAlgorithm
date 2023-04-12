#include <iostream>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    int X;
    cin >> N >> X;
    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        if (num < X) cout << num << ' ';
    } 
}
