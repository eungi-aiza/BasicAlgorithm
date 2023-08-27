#include <iostream>
using namespace std;

void backtracking(
  int* arr,
  int curr,
  int N,
  int M){ 
    if (curr == M){
      for (int i=0; i<M; i++){
        cout << arr[i] << " ";
      }
      cout << "\n";
      return;
    }    

    for (int i=1; i<=N; i++){  
      arr[curr] = i; 
      backtracking(arr, curr+1, N, M);
    }
}


int main(){
  int N;
  int M;
  cin >> N >> M;

  int arr[10] = {};
  backtracking(arr, 0, N, M);
  return 0;
}