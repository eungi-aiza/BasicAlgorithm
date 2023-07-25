#include <iostream>
// N과 M (1) Permutation
using namespace std;
int N, M;
int arr[10];
int isused[10];
void func(int k){
    if (k == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for (int i = 0; i < N; i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[k] = i+1;
            func(k+1);
            isused[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0);

}