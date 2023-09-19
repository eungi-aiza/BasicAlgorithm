#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        unordered_map<int, int> path_count;
        dfs(root, path_count, count);
        return count;
    }

    void dfs(TreeNode* node, unordered_map<int, int>& path_count, int& count) {
        if (!node) {
            return;
        }

        path_count[node->val]++;

        if (!node->left && !node->right) {
            if (is_palindrome(path_count)) {
                count++;
            }
        }

        dfs(node->left, path_count, count);
        dfs(node->right, path_count, count);

        path_count[node->val]--;
        if (path_count[node->val] == 0) {
            path_count.erase(node->val);
        }
    }

    bool is_palindrome(unordered_map<int, int>& path_count) {
        int odd_count = 0;
        for (const auto& pair : path_count) {
            if (pair.second % 2 == 1) {
                odd_count++;
            }
            if (odd_count > 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution solution;
    int result = solution.pseudoPalindromicPaths(root);
    cout << "Example Output: " << result << endl;  // Output: 2

    return 0;
}
