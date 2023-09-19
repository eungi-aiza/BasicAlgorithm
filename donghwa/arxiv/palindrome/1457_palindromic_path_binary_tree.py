class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def pseudoPalindromicPaths(root):
    def is_palindrome(s):
        odd_count = 0
        for count in s.values():
            if count % 2 == 1:
                odd_count += 1
            if odd_count > 1:
                return False
        return True

    def dfs(node, path):
        if not node:
            return

        path[node.val] = path.get(node.val, 0) + 1

        if not node.left and not node.right:
            nonlocal count
            if is_palindrome(path):
                count += 1

        dfs(node.left, path.copy())
        dfs(node.right, path.copy())

    count = 0
    dfs(root, {})
    return count

# Test case
root = TreeNode(2)
root.left = TreeNode(3)
root.right = TreeNode(1)
root.left.left = TreeNode(3)
root.left.right = TreeNode(1)
root.right.right = TreeNode(1)

print("Example Output:", pseudoPalindromicPaths(root))  # Output: 2
