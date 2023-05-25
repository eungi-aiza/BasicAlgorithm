#include <iostream>
#include <deque>
using namespace std;


int check(string func){
    deque<char> D;
    int A_flag = 0;
    int B_flag = 0;
    for (auto c : func){
        if (c == 'A'){
            if (A_flag > 0 && D.back() == 'A') {
                D.pop_back();
                A_flag --;
            }
            else {
                D.push_back('A');
                A_flag ++;
            }
        }
        else if (c == 'B'){
            if (B_flag > 0 && D.back() == 'B') {
                D.pop_back();
                B_flag --;
            }
            else {
                D.push_back('B');
                B_flag ++;
            }
        }
    }
    if (D.size() == 0) return 1;
    else return 0;
}

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    int ans = 0;
    for (int i=0; i<N; i++){
        string func;
        cin >> func;
        ans += check(func);
    }
    cout << ans;
}