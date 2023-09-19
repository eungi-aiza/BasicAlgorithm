/* 1457. Pseudo-Palindromic Paths in a Binary Tree
Given a binary tree where node values are digits from 1 to 9. 
A path in the binary tree is said to be pseudo-palindromic 
if at least one permutation of the node values in the path is a palindrome.
Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

ex1.
Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. 
There are three paths going from the root node to leaf nodes: 
the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. 
Among these paths only red path and green path are pseudo-palindromic paths 
since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).

ex2.
Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. 
There are three paths going from the root node to leaf nodes: the green path [2,1,1], 
the path [2,1,3,1], and the path [2,1]. 
Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).

ex3.
Input: root = [9]
Output: 1

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_palindrome(int *count) {
    int odd_count = 0;
    for (int i = 1; i <= 9; i++) {
        if (count[i] % 2 == 1) {
            odd_count += 1;
        }
        if (odd_count > 1) {
            return false;
        }
    }
    return true;
}

void dfs(struct TreeNode *node, int *path, int *count, int *result) {
    if (!node) {
        return;
    }

    path[node->val] = path[node->val] + 1;

    if (!node->left && !node->right) {
        if (is_palindrome(path)) {
            (*result)++;
        }
    }

    dfs(node->left, path, count, result);
    dfs(node->right, path, count, result);
    path[node->val] = path[node->val] - 1;
}

int pseudoPalindromicPaths(struct TreeNode *root) {
    int path[10] = {0};
    int result = 0;

    dfs(root, path, &result);
    return result;
}

int main() {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = 2;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 3;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 1;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->val = 1;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->val = 1;

    int result = pseudoPalindromicPaths(root);
    printf("Example Output: %d\n", result);  // Output: 2

    return 0;
}


