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