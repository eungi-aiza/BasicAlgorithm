// N과 M(2) Combination
#include <iostream>
int N, M;
int arr[10];
int isused[10];
using namespace std;
void func(int k, int st){
    if(k == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout <<'\n';
        return;
    }
    for (int i = st; i < N; i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[k] = i+1;
            func(k+1, i+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0, 0);
}