#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_V 100  // Maximum number of vertices
#define INF INT_MAX

int num_strings = 0;
char* strings[100]; // Initialize an array of character pointers
char temp[100];
int vis[100];
int length = 0;

void backtracking(char* s, int curr){
    if (curr == length){
        temp[curr] = '\0'; // Null-terminate the temporary string
        strings[num_strings] = (char*)malloc(strlen(temp) + 1);
        strcpy(strings[num_strings], temp);
        num_strings++;
        return;        
    }
    char prev = '\0';
    for (int i=0; i<length; i++){
        if (vis[i] == 1) continue;
        if (s[i] == prev) continue;
        vis[i] = 1;
        temp[curr] = s[i];
        prev = temp[curr];
        backtracking(s, curr+1);
        vis[i] = 0;
    }
}

char** str_perm(char* s){
    length = strlen(s); // Calculate the length of the input string
    backtracking(s, 0);

    // Sort the generated strings in lexicographical order
    for (int i = 0; i < num_strings - 1; i++) {
        for (int j = i + 1; j < num_strings; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                char* temp_str = strings[i];
                strings[i] = strings[j];
                strings[j] = temp_str;
            }
        }
    }
    return strings;
}

int main(){
    char s[100] = "abb";
    char** ans = str_perm(s);
    for (int i=0; i<num_strings; i++){
        printf("%s ", ans[i]);
        free(ans[i]); // Free the allocated memory for each string
    }
    return 0;
}
