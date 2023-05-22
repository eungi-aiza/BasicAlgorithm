#include <bits/stdc++.h>
using namespace std;

int N,M;
int target, idx;
deque<int> Q;
int cnt = 0;

int main(){
    cin >> N >> M;

    for (int i=1; i<=N; i++){
        Q.push_back(i);
    }

    while(M--){
        cin >> target;

        for (int j=0;j<Q.size();j++){
            if (Q[j]==target){
                idx = j; //아래의 range값 idx 기준으로 봐야함!!!
                break;
            }
        }
        if (idx <= Q.size()/2){
            for (int k=0;k<idx;k++){
                Q.push_back(Q.front());
                Q.pop_front();
                cnt++;
            }
            Q.pop_front();
        }
        else {
            for (int k=0; k<Q.size()-idx;k++){
                Q.push_front(Q.back());
                Q.pop_back();
                cnt++;
            }
            Q.pop_front();
        }
    }


    cout << cnt;
}

