class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution_myori:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 and not l2:  # 漏了特判
            return None
        head = ListNode()
        L = head
        while l1 != None or l2 != None:
            # print(l1.val, l2.val)
            if l1 and l2:  # 都为空
                if l1.val < l2.val:
                    L.val = l1.val
                    l1 = l1.next
                elif l1.val > l2.val:
                    L.val = l2.val
                    l2 = l2.next
                else:
                    L.val = l1.val
                    L.next = ListNode()
                    L = L.next
                    L.val = l1.val
                    l1 = l1.next
                    l2 = l2.next
                if l1 or l2:
                    L.next = ListNode()
                    L = L.next
            else:
                while l1:
                    L.val = l1.val
                    l1 = l1.next
                    if l1:
                        L.next = ListNode()
                        L = L.next
                while l2:
                    L.val = l2.val
                    l2 = l2.next
                    if l2:
                        L.next = ListNode()
                        L = L.next
        return head


'''
改进：当一个表空了的时候，直接把ret list接到原来那个表就行了。。
'''
if __name__ == '__main__':
    S = Solution()
