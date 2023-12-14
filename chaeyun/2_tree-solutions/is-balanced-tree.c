/* Definition for a binary tree node.                   */
/* struct TreeNode {                                    */
/*     int val;                                         */
/*     struct TreeNode *left;                           */
/*     struct TreeNode *right;                          */
/* };                                                   */
int depth(struct TreeNode *root);

bool isBalanced(struct TreeNode *root) {
    if (root == NULL)
        return true;
        
    return isBalanced(root->left) && 
           isBalanced(root->right) &&
           !(abs(depth(root->left) - depth(root->right)) > 1);
}

int depth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
        
    return fmax(depth(root->left), depth(root->right)) + 1;
}