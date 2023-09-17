/* 알파벳 찾기
알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

- 입력 : 
첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

- 출력 :
각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.

만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.

ex1. 
- 입력 :
baekjoon
- 출력 : 
1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

 
*/

#include <stdio.h>
#include <string.h>
#define ALPHABET_COUNT 26

void initialize(int * positions){
    for (int i=0; i<ALPHABET_COUNT; i++){
        positions[i] = -1;
    }
};
void savePosition(int* positions, char* S){
    for (int i=strlen(S)-1; i>=0; i--){
        int tmp = S[i] -'a';
        positions[tmp] = i;
    }
};

int main(){
    char S[100];
    scanf("%s", S);

    int pos[ALPHABET_COUNT];
    initialize(pos);
    savePosition(pos, S);
    
    for (int i=0; i<ALPHABET_COUNT; i++){
        printf("%d ", pos[i]);
    } printf("\n");

}
