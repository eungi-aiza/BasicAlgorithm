#include <stdio.h>


// void func2(int arr[], int N){
//     int ans = 0;

//     for (int i=0;i<N;i++)
//         for (int j=i+1;j<N;j++){
//             if (arr[i] + arr[j] == 100) 
//                 ans = 1;
//         }
    
//     printf("%d", ans);
// }

// int main() {
//     int n;
//     scanf("%d", n);
//     int check[n];
//     for (int i=0;i<n;i++){
//         scanf("%d", check[i]);
//     }

//     func2(check, n);

//     return 0;
// }

int func2(int arr[], int N){
  int occur[101] = {};
  for(int i = 0; i < N; i++){
    if(occur[100-arr[i]] == 1)
      return 1;
    occur[arr[i]] = 1;
  }
  return 0;
}