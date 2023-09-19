#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    char arr[1005];
    scanf("%d", &n);
    scanf("%s", arr);
    int t = 0;
    for (int i=0; i<n; i++){
        t += arr[i] - '0';
    }
    printf("%d", t);
}