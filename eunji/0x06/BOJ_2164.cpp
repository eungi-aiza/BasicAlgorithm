#include <iostream>
#include <queue>
using namespace std;

int main(void){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N;
    cin >> N;
    queue<int> Q;
    for (int i=0; i<N; i++){
        Q.push(i+1);
    }
    int flag;
    flag = 1;
    while (Q.size() != 1){
        if (flag == 1) Q.pop();
        else if (flag == -1){
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
        flag *= -1;      
    }
    cout << Q.front();
}