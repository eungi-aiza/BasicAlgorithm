/*
자연수 n에 대해서, 어떠한 자연수 k 에 대해서도 k 와 k 의 각 자리 수를 모두 더했을 때 n 으로 만들 수 없으면, n을 self number라고 한다. 
(https://en.wikipedia.org/wiki/Self_number)
예를 들어, 21 = 15 + 1 + 5 이므로(n = 21, k = 15) 21 은 self number 가 아니다.
또 다른 예로, 19 = 14 + 1 + 4 이므로 (n=19, k=14) 19 역시 self number 가 아니다. 반면 20 은 그러한 k 가 존재하지 않으므로 self number 가 맞다.
자연수 x을 입력 받아서 x보다 큰 최소의 self number 를 return 하는 함수를 구현하시오. (x는 32비트로 표현 가능한 자연수 범위 내의 수이다.)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int P4_Help(int n){
  int ans = n;
  while(n != 0){
    ans += n%10;
    n /= 10;
  }
  return ans;
}


  /* Write code here */ 
int P4(int n){
  bool check = false ;
  while(~check){
    n++;
    int sum, i;
    for (i=n-1; i>0; i--){
      sum = P4_Help(i);
      if (sum == n){
        check = false; 
        break;
      }
    }
    if (i == 0){
      check = true;
      break;
    }
  } 
  return n;
    /* End of your code */ 
}

// DO NOT MODIFY BELOW!
int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int ans = P4(n);

    printf("%d\n", ans);

    return 0;
}