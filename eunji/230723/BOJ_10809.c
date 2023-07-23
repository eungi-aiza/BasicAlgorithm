#include <stdio.h>
#include <string.h> 

#define ALPHABET_COUNT 26

void initialize(int* positions){
    for (int i=0; i<ALPHABET_COUNT; i++){
        positions[i] = -1;
    }
}

void savePosition(int* positions, char* S){
    int len = 0; 
    // int len = strlen(S);
    for (int i=0; S[i] != '\0'; i++){
        len ++;
    }
    for (int i=0; i<len; i++){
        int temp =  S[i] - 'a'; // 이 부분이 핵심
        if (positions[temp] == -1){
            positions[temp] = i;
        }
    }

}

int main(){
    char S[101];
    scanf("%s", S);
    int positions[ALPHABET_COUNT];
    initialize(positions);
    savePosition(positions, S);
    for (int i=0; i<ALPHABET_COUNT; i++){
        printf("%d ", positions[i]);
    }
} 