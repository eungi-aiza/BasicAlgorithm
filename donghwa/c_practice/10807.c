#include <stdio.h>
int c[105];
int n, v;
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &c[i]);
    }
    scanf("%d", &v);
    int cnt =0;
    for (int i=0; i<n; i++){
        if (c[i] == v){
            cnt += 1;
        }
    }
    printf("%d", cnt);
}