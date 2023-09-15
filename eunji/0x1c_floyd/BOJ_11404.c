#include <stdio.h>

#define INF (0x3f3f3f3f)

int min(int a, int b){
    if (a < b) return a;
    else return b;
}

int main(){
    int n;
    int m;
    int arr[102][102];
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    for (int i=0; i<m; i++){
        int st;
        int ed;
        int cost;
        scanf(" %d %d %d", &st, &ed, &cost);
        if (arr[st][ed] > cost) arr[st][ed] = cost; 
    }
    for (int m=1; m<=n; m++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][m]+arr[m][j]);
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (arr[i][j] >= INF) printf("0 ");
            else printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}