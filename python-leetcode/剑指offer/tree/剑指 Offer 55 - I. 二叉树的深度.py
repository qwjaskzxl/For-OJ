pass
'''
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 

提示：

节点总数 <= 10000
'''


# Definition for a binary tree node.

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        MAX = 0

        def dfs(node, depth):
            nonlocal MAX
            if not node:
                return
            if depth > MAX:
                MAX = depth
            if node.left: dfs(node.left, depth + 1)
            if node.right: dfs(node.right, depth + 1)

        dfs(root, 1)
        return MAX


class Solution_666:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return max(self.maxDepth(root.left),
                   self.maxDepth(root.right)) \
               + 1
