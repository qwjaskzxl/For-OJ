pass
'''
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
'''


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution_wrong:  # 题目理解错了，是整棵树对称，不是每个子树对称
    def isSymmetric(self, root: TreeNode) -> bool:
        flag = True
        if root:
            queue = [root]
            while queue:
                node = queue[0]
                if node.left and node.right:
                    if node.left.val != node.right.val:
                        flag = False
                        break
                    queue.append(node.left)
                    queue.append(node.right)
                elif node.left != None or node.right != None:
                    flag = False
                    break

                del queue[0]
        return flag


'''
对称二叉树定义： 对于树中 任意两个对称节点 LL 和 RR ，一定有：
L.val = R.valL.val=R.val ：即此两对称节点值相等。
L.left.val = R.right.valL.left.val=R.right.val ：即 LL 的 左子节点 和 RR 的 右子节点 对称；
L.right.val = R.left.valL.right.val=R.left.val ：即 LL 的 右子节点 和 RR 的 左子节点 对称。

### 所以我定义都没搞清。。。
'''


class Solution:

    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True

        def recur(L, R):
            if not L and not R:  # 两个都是None
                return True
            elif (not L or not R)or R.val != L.val:#只有一个是None，或都不是None但val不同
                return False

            return recur(L.left, R.right) and recur(R.left, L.right)  # 虽然是自顶向下，但有种自底向上的感觉

        return recur(root.left, root.right)


print(None == None)
