#include <stdio.h>

struct Node{
    char left;
    char right;
    char val;
};

void dfs1(struct Node* arr, int curr){
    printf("%c", arr[curr].val);
    if (arr[curr].left != '.'){
        dfs1(arr, arr[curr].left-'A');
    }
    if (arr[curr].right != '.'){
        dfs1(arr, arr[curr].right-'A');
    }
}

void dfs2(struct Node* arr, int curr){
    if (arr[curr].left != '.'){
        dfs2(arr, arr[curr].left-'A');
    }
    printf("%c", arr[curr].val);
    if (arr[curr].right != '.'){
        dfs2(arr, arr[curr].right-'A');
    }
}

void dfs3(struct Node* arr, int curr){
    if (arr[curr].left != '.'){
        dfs3(arr, arr[curr].left-'A');
    }
    if (arr[curr].right != '.'){
        dfs3(arr, arr[curr].right-'A');
    }
    printf("%c", arr[curr].val);
}

int main(){
    struct Node arr[26];
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        char H; 
        char L; 
        char R;
        scanf(" %c %c %c", &H, &L, &R);
        i = H - 'A';
        arr[i].val = H;
        arr[i].left = L;
        arr[i].right = R;
    }
    dfs1(arr, 0);
    printf("\n");
    dfs2(arr, 0);
    printf("\n");
    dfs3(arr, 0);

}