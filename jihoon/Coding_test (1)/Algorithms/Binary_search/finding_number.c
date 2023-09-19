// BOJ 1920 수찾기
#include <stdio.h>
#include <stdlib.h>
int arr[100002];

int binarysearch(int x, int n){
    int st = 0; int en = n-1;
    while(st <= en){
        int mid = st + (en-st)/2;
        if(arr[mid] == x) return 1;
        else if (arr[mid] > x) en = mid-1;
        else st = mid + 1;
    }
    return 0;
}

int ascending(const void *a, const void *b) {
    if (*(int *)a > *(int *)b) return 1;
    else if (*(int *)a < *(int *)b) return -1;
    else return 0;
}
int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), ascending);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int x; scanf("%d", &x);
        printf("%d\n", binarysearch(x, n));
    }

}