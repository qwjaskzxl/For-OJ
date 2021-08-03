'''
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000
'''


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution_wrong:  # 题目理解错了，我以为要去重，不过我这个代码写的也不对，那里TLE了
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None: return l2
        if l2 == None: return l1

        if l1.val > l2.val:  # 确保l1是小的，因为我想把l2加到l1里
            l1, l2 = l2, l1
        head = l1
        while l2 != None:
            if l1.next != None:
                nxt = l1.next
                if l1.val < l2.val < nxt.val:
                    l1.next = l2
                    l1.next.next = nxt
                    l1 = l1.next
                    l2 = l2.next
                elif l2.val <= l1.val:
                    l2 = l2.next
                elif l2.val >= nxt.val:
                    l1 = nxt

            else:
                while l2.val < l1.val and l2 != None:
                    l2 = l2.next
                l1.next = l2
                break

        return head


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = cur = ListNode(0)
        while l1 and l2:  # 有一个None了，就stop，然后处理尾巴即可
            if l1.val < l2.val:
                cur.next, l1 = l1, l1.next
            else:
                cur.next, l2 = l2, l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        return head.next


S = Solution()
# print()
