#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> S;
    vector<char> ans;
    int cnt = 1;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;

        while (cnt <= x){
            S.push(cnt);
            cnt ++;
            ans.push_back('+');
        }
        if (S.top() == x){
            S.pop();
            ans.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }


    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}