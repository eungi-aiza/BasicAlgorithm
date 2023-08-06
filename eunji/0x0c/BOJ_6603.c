#include <stdio.h>
#include <stdlib.h>


void backtracking(
  int start,
  int* input,
  int* arr,
  int* isused,
  int curr,
  int k
){
  isused[start] = 1;
  arr[curr] = input[start];
  if (curr == 5){
    for (int i=0; i<6; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  
  for (int i=start+1; i<k; i++){
    if (!isused[i]){
      backtracking(i, input, arr, isused, curr+1, k);
      isused[i] = 0;
      // arr[i] = input[start];
    }
  }

}

int main(){
  while (1){
    int k;
    int arr[6] = {};
    int input[14] = {};
    int isused[14] = {};
    scanf("%d", &k);
    if (k == 0){
      break;
    }
    for (int i=0; i<k; i++){
      scanf("%d", &input[i]);
    }
    for (int i=0; i<=k-6; i++){
      backtracking(i, input, arr, isused, 0, k);
    }
    printf("\n");
  }
  return 0;
}