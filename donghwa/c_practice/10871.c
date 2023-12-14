#include <stdio.h>
int c[10005];
int n, v;
int main(){
    scanf("%d", &n);
    scanf("%d", &v);
    for (int i=0; i<n; i++){
        scanf("%d", &c[i]);
    }
    int cnt =0;
    for (int i=0; i<n; i++){
        if (c[i] < v){
            printf("%d ", c[i]);
        }
    } 
    
}