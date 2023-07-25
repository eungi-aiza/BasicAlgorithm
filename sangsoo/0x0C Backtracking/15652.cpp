#include <iostream>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void func(int k, int st){
    if(k == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return; // return 꼭 넣어줘야 함        
    }
    for(int i = st; i < N; i++){
        arr[k] = i + 1;
        func(k+1, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M ;
    func(0, 0);
}