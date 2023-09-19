/*
 * 257. Binary Tree Paths
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any order.
 * 
 * A leaf is a node with no children.
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * -100 <= Node.val <= 100
 */

#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

void dfs(struct TreeNode* root, int *buf, int len, char **ans, int *returnSize)
{
    int tmp;

    if (root) {
    
        /* Add node value to integer buffer */
        buf[len] = root->val;
        len++;

        if (root->left == NULL && root->right == NULL) {
            ans[*returnSize] = (char *)malloc(sizeof(char) * 512);

            for (int i = 0, j = 0; i < len; i++) {

                /* Convert integer to string */
                if (buf[i] != 0) {

                    if (buf[i] < 0) {
                        ans[*returnSize][j] = '-';
                        j += 1;
                    }

                    tmp = abs(buf[i]);

                    if (tmp >= 1 && tmp <= 9) {
                        ans[*returnSize][j] = tmp + '0';
                        j += 1;
                    }
                    else if (tmp >= 10 && tmp <= 99) {
                        ans[*returnSize][j] = (tmp / 10) + '0';
                        ans[*returnSize][j + 1] = (tmp % 10) + '0';
                        j += 2;
                    }
                    else {
                        ans[*returnSize][j] = '1';
                        ans[*returnSize][j + 1] = '0';
                        ans[*returnSize][j + 2] = '0';
                        j += 3;
                    }
                }
                else {
                    ans[*returnSize][j] = '0';
                    j += 1;
                }

                /* Add arrow if needed */
                if (i != len - 1) {
                    ans[*returnSize][j] = '-';
                    ans[*returnSize][j + 1] = '>';
                    j += 2;
                }

                /* End of string */
                ans[*returnSize][j] = 0;
            }

            (*returnSize)++;
        }
        else {
            dfs(root->left, buf, len, ans, returnSize);
            dfs(root->right, buf, len, ans, returnSize);
        }
    }
} 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){

    /*
     * Input:
     *  root, root of binary tree
     */

    char **ans = (char **)calloc(1, sizeof(char *) * 100);
    int buf[100];

    *returnSize = 0;

    dfs(root, buf, 0, ans, returnSize);
    
    /*
     * Output:
     *  *returnSize, number of strings
     *  return all root-to-leaf paths in any order.
     */

    return ans;
}