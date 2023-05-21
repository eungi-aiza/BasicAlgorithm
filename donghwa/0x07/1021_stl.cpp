#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int N, M;
    cin >> N;
    cin >> M;
    while(N--){
        DQ.push_front(N+1);
    }
    int cnt=0;
    while(M--){
        int num;
        cin >> num;
        if (DQ.front() == num){
            DQ.pop_front();
        } else {
            int trg = 0;
            for(auto x : DQ){
                if (x == num){
                    break;
                } else { trg++;}
            }
            if (trg <= trg-DQ.size()){
                while(trg--){
                    DQ.pop_front();
                    cnt++;
                }
            } else {
                while(trg<DQ.size()){
                    DQ.pop_back();
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    // for(auto c : DQ){
    //     cout << c << ' ';
    // } cout << '\n';
}