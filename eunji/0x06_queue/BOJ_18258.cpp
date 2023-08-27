#include <iostream>
#include <queue>
using namespace std;


int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    queue<int> Q;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string order;
        cin >> order;
        if (order == "push"){
            int new_;
            cin >> new_;
            Q.push(new_);
        }
        else if (order == "pop"){
            if (Q.size() > 0){
                int tar;
                tar = Q.front();
                Q.pop();
                cout << tar << '\n';
            }
            else cout << -1 << '\n';
        }  
        else if (order == "size") cout << Q.size() << '\n';
        else if (order == "empty") cout << Q.empty() << '\n';
        else if (order == "front"){
            if (Q.size() > 0) cout << Q.front() << '\n';
            else cout << -1 << '\n';
        }  
        else if (order == "back"){
            if (Q.size() > 0) cout << Q.back() << '\n';
            else cout << -1 << '\n';
        }   
    }
}