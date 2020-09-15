# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        n1, n2 = '', ''
        head = ListNode(None)
        while l1 != None:
            n1 += str(l1.val)
            l1 = l1.next
        while l2 != None:
            n2 += str(l2.val)
            l2 = l2.next

        res = str(int(n1[::-1]) + int(n2[::-1]))[::-1]
        head.val = int(res[0])

        # cur = head
        nxt = head.next  # 这样其实很蠢啊，
        for i in range(len(res) - 1):
            # cur.next = ListNode(int(res[i+1]))
            # cur = cur.next
            nxt = ListNode(int(res[i + 1]))
            nxt = nxt.next
        return head


if __name__ == '__main__':
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    S = Solution()
    print(S.addTwoNumbers(l1, l2))
