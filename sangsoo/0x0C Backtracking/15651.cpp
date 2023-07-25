// isused를 빼면 복원 추출이 된다. 
#include <iostream>
using namespace std;
int N, M;
int arr[10];
int isused[10];
void func(int k){
    if(k == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return; // return 꼭 넣어주자.
    }
    for(int i = 0; i < N; i++){
        arr[k] = i+1;
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);
}