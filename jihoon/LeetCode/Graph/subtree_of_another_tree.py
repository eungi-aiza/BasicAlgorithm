from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        q = deque()
        q.append(root)
        while q:
            thisNode = q.popleft()
            if thisNode.val == subRoot.val:
                isSame = compare(thisNode, subRoot)
                if isSame:
                    return True
            if thisNode.left:
                q.append(thisNode.left)
            if thisNode.right:
                q.append(thisNode.right)
        return False
            
            
        
        
def compare(root1, root2):
    if not root1 and not root2:
        return True
    if not root1:
        return False
    if not root2:
        return False
    if root1.val == root2.val:
        leftCompare = compare(root1.left, root2.left)
        rightCompare = compare(root1.right, root2.right)
        return leftCompare and rightCompare
    return False