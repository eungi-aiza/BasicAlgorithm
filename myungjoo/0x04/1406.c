#include <stdio.h>
#define R_MAX 300000

char L[600000+10];
char R[R_MAX+10];

int main(){
	int left = 0, right = R_MAX, N = 0, op = 0;
	char add;
	scanf("%s", L);
	while(L[left++]); left--;
	scanf("%d", &N);
	while(N--){
		scanf("\n%c", &op);
		if ( op == 'P'){
			scanf(" %c", &add);
			L[left++] = add;
		}
		else if (op == 'L' && left != 0 ){
			R[right--] = L[--left];
			L[left] = '\0';
		}
		else if ( op == 'B' && left != 0){
			L[--left] = '\0';
		}
		else if ( op == 'D' && right!= R_MAX){
			L[left++] = R[++right];
			R[right] = '\0';
		}
		//printf("%s %s\n", L, &R[right+1]);
	}
	printf("%s%s", L, &R[right+1]);
}