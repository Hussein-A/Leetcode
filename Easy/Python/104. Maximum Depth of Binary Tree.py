#Given a binary tree, find its maximum depth.
#The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
#Note: A leaf is a node with no children.

#Runtime: (48ms) Faster than  87.69% of Python submissions; MEM: (15.3mb) 

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        return 1 +max(self.maxDepth(root.left), self.maxDepth(root.right)) if root else 0
      
