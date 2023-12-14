
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isBalanced(self, root) -> bool:
        def height(root):
            if root == None:
                return 0
            
            h_left = height(root.left)
            if h_left < 0:
                return -1
            h_right = height(root.right)
            if h_right < 0 or abs(h_left - h_right) > 1:
                return -1

            return max(h_left, h_right) + 1
        
        return height(root) >= 0