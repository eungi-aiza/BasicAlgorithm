#include <iostream>
#include <stack>
using namespace std;


int main(void){
    stack<int> S;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        string order;
        cin >> order;
        if (order == "push"){
            int tar;
            cin >> tar;
            S.push(tar);
        }
        else if (order == "pop"){
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n'; 
                S.pop();
                }
        }
        else if (order == "top"){
            if (S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }
        else if (order == "size"){
            cout << S.size() << '\n';
        }
        else if (order == "empty"){
            cout << S.empty() << '\n';          
        }
    }
}