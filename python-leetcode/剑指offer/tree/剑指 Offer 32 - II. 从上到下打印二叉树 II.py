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


class Solution_wrong:  # 记录深度，太麻烦了
    def levelOrder(self, root: TreeNode) -> list:
        if not root: return []
        queue = [root]
        dict = {0: [root.val]}
        deep = {root: 0}
        while queue:  # 删除：remove(first_value), del(index)
            node = queue[0]
            if node.left or node.right:
                dict[deep[node] + 1] = []
                if node.left:
                    queue.append(node.left)
                    deep[node.left] = deep[node] + 1
                    dict[deep[node.left]].append(node.left.val)
                if node.right:
                    queue.append(node.right)
                    deep[node.right] = deep[node] + 1
                    dict[deep[node.right]].append(node.right.val)
            del queue[0]
        return list(dict.values())


class Solution:
    def levelOrder(self, root: TreeNode) -> list:
        if not root: return []
        queue = [root]
        res = []
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

            res.append(tmp)
        return res


print(list({1: [21, 2], 2: [2]}.values()))
a = {}
a[1] = 1
