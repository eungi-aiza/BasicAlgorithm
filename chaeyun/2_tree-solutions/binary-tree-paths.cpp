#include<iostream>
#include<string>
#include <vector>
using namespace std;

/**
Given the root of a binary tree, return all root-to-leaf paths in any order.
root = [1, 2, 3, null, 5]
output : ["1->2->5","1->3"]
**/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void addPath(TreeNode* root, string temp, vector<string>& ans) {
        if (root == nullptr) {
            return;
        }

        if(root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val) + "->";

        addPath(root->left,temp,ans);
        addPath(root->right,temp,ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";

        if(root == NULL) 
            return ans;

        addPath(root,temp,ans);

        return ans;
    }
};