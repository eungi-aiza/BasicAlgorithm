#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int number[100001];
int pos = 0;

void push(int num){
    number[pos] = num;
    pos++;
}

void pop(){
    if (pos!=0){
        pos--;
        printf("%d\n", number[pos]);
    }
    else {
        printf("%d\n", -1);
    }
}

void size(){
    printf("%d\n", pos);
}

void empty(){
    if (pos==0){
        printf("%d\n", 1);
    }
    else
        printf("%d\n", 0);
}

void top(){
    if (pos!=0){
        printf("%d\n", number[pos-1]);
    }
    else {
        printf("%d\n", -1);
    }
}
int main(){
    int N, input;
    char command[10] = {0, };

    scanf("%d", &N);

    for (int i=0;i<N;i++){
        scanf("%s", command);
        if (strcmp(command,"push")==0){
            scanf("%d", &input);
            push(input);
        }
        else if(strcmp(command,"pop")==0){
            pop();
        }
        else if(strcmp(command,"empty")==0){
            empty();
        }
        else if(strcmp(command,"size")==0){
            size();
        }
        else if(strcmp(command,"top")==0){
            top();
        }

    }

    return 0;
    }



