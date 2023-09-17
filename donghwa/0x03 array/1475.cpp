/* 방번호
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
(6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

- 입력:
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

- 출력 :
첫째 줄에 필요한 세트의 개수를 출력한다.

ex1.
- 입력 :
9999
- 출력 :
2
*/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[10] = {0};
    while(true){
        if (n%10 == 6 || n%10 == 9){
            if (arr[6] < arr[9]){
                arr[6]++;
            } else{
                arr[9]++;
            }
        } else{
            arr[n%10]++;
        }
        if (n/10 == 0) break;
        n /= 10;
    }    
    int maxn = arr[0];
    for (int i=1; i<10; i++){
        maxn = max(arr[i], maxn);
    }
    cout << maxn <<endl;
}