// //Q2752. 세수정렬

// #include <stdio.h>

// int main() {
//     int a, b, c, max, min, mid;
//     scanf("%d %d %d", &a, &b, &c);

//     max = a;
//     if (max<b){
//         max = b;
//     }
//     if (max<c){
//         max = c;
//     }

//     min = a;
//     if (min>b){
//         min = b;
//     }
//     if (min>c){
//         min = c;
//     }

//     if (a!=max && a!=min){
//         mid = a;
//     }
//     else if(b!=max && b!=min){
//         mid = b;
//     }
//     else{
//         mid = c;
//     }

//     printf("%d %d %d", min, mid, max);

//     return 0;
// }

//Q2587. 대표값2
#include <stdio.h>

int main(){
    int num[5];
    int sum=0;
    int mid=0;

    for (int i=0;i<5;i++){
        scanf("%d", &num[i]);
    };

    int i = 0;
    while (i < 5){
        sum += num[i];
        i++;
    };
    sum /= 5;

    mid = num[5/2];

    printf("%d\n", sum);
    printf("%d", mid);

    return 0;
}