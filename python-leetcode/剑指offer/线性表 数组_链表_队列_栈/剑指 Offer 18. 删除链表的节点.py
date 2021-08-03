# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        while head.val == val:  # 因为要return ListNode，所以首先把head定位到第一个非val的地方
            head = head.next
        cur = head
        nxt = cur.next
        while nxt != None:  # 这里防止一开始nxt就是None
            # print(cur.val)
            if nxt.val == val:
                cur.next = nxt.next
            if cur.next == None:  # 这里防止要删除的是last node，nxt没有next
                break
            cur = cur.next
            nxt = cur.next
        return head


S = Solution()
# print(S.deleteNode())
