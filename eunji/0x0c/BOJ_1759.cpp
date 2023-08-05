#include <iostream>
#include <algorithm>
using namespace std;

void backtracking(
  int start,
  char* arr,
  int* iu,
  char* input,
  int L,
  int C,
  int curr,
  int c_count,
  int a_count
){
  iu[start] = 1;
  arr[curr] = input[start];
  if (arr[curr] == 'a' || arr[curr] == 'e' || arr[curr] == 'i' || arr[curr] == 'o' || arr[curr] == 'u'){
    a_count ++;
  }
  else c_count ++;

  if (curr == L-1 && a_count > 0 && c_count > 1){
    for (int i=0; i<L; i++){
      cout << arr[i];
    }
    cout << "\n";
    return;
  }
  for (int i=start+1; i<C; i++){
    if (iu[i] != 1 && input[i] > input[start]){
      backtracking(i, arr, iu, input, L, C, curr+1, c_count, a_count);
      iu[i] = 0;
    }
  }
}


int main(){
  int L;
  int C;
  cin >> L >> C;
  char input[16];
  for (int i=0; i<C; i++){
    cin >> input[i];
  }

  // Sort the input characters in lexicographic order.
  sort(input, input+C);

  char arr[16] = {};
  int iu[16] = {};
  for (int i=0; i<=C-L; i++){
    backtracking(i, arr, iu, input, L, C, 0, 0, 0);
  }
  return 0;
}