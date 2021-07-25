'''定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

限制：
0 <= 节点个数 <= 5000
'''


class ListNode:  # Definition for singly-linked list.
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:  # 迭代法 or 递归法
        cur = head
        ### 这样会有两个None，一个val, 一个next，
        # prev, nxt = ListNode(None), ListNode(None)
        prev, nxt = None, None
        ### 终止边界？
        while cur != None:  # 判断边界的时候，就想一下：最后这时候，代码要不要执行->才能完成功能
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        ### 返回什么？
        return prev


class Solution_666:
    def reverseList(self, head: ListNode) -> ListNode:
        cur, pre = head, None
        while cur:
            cur.next, pre, cur = pre, cur, cur.next  # 666
        return pre


S = Solution()
# print(S.reverseList())
