#include <iostream>
using namespace std;

void backtracking(
  int start,
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
      backtracking(i, arr, curr+1, N, M);
    }
}


int main(){
  int N;
  int M;
  cin >> N >> M;

  int arr[10] = {};

  for (int i=1; i<=N; i++){
    arr[0] = i;
    backtracking(i, arr, 1, N, M);
  }

  return 0;
}