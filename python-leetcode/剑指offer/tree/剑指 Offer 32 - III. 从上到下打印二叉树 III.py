'''
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
'''


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> list:
        if not root: return []
        queue = [root]
        res = []
        i = 0
        while queue:
            tmp = []
            for _ in range(len(queue)):  # 一次一层
                node = queue[0]
                tmp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                del queue[0]
            if i % 2:
                tmp = tmp[::-1]  # 我tm刚开始在queue那边倒来倒去，不过这样多一个运算。正解是用双端队列，一个插head一个插tail
            i += 1
            res.append(tmp)
        return res


print(list({1: [21, 2], 2: [2]}.values()))
a = {}
a[1] = 1
