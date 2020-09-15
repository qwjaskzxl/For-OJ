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
        # 法1：用str和int直接转的stupid方法，不过这样没有特判了吧
        # n1, n2 = '', ''
        # while l1 != None:
        #     n1 += str(l1.val)
        #     l1 = l1.next
        # while l2 != None:
        #     n2 += str(l2.val)
        #     l2 = l2.next
        # res = str(int(n1[::-1]) + int(n2[::-1]))[::-1]
        #
        # head = ListNode(None)
        # head.val = int(res[0])
        # cur = head
        # # nxt = head.next  # 这样其实很蠢啊，
        # for i in range(len(res) - 1):
        #     cur.next = ListNode(int(res[i + 1]))
        #     cur = cur.next
        #     # nxt = ListNode(int(res[i + 1]))
        #     # nxt = nxt.next

        # 法2，不借助str
        head = ListNode(None)
        cur = head
        carry = 0  # 进位
        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

            N = v1 + v2 + carry
            carry = N // 10
            cur.val = N % 10
            if carry > 0 and l1 == None and l2 == None:  # 这个就要加特判，必须得想到
                cur.next = ListNode(carry)
            if l1 or l2:
                cur.next = ListNode(None)
            cur = cur.next

        return head


if __name__ == '__main__':
    l1 = ListNode(5)
    # l1.next = ListNode(4)

    l2 = ListNode(5)
    l2.next = ListNode(1)
    # l2.next.next = ListNode(4)

    S = Solution()
    L = S.addTwoNumbers(l1, l2)
    while L:
        print(L.val)
        L = L.next
