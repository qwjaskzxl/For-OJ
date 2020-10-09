class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        # return len(self.items) == 0
        return self.items == []

    def push(self, x):
        self.items.append(x)

    def pop(self):
        return self.items.pop()

    def top(self):
        idx = len(self.items) - 1  # 栈顶
        return self.items[idx]


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        st = Stack()  # 栈的特性就是能让最近的元素能比较，括号这种就很典型，因为一个left之后必须跟一个right
        left = ['(', '[', '{']
        right = [')', ']', '}']
        for x in s:
            for i in range(len(left)):
                if x == left[i]:
                    st.push(x)
                    break
                if x == right[i]:
                    if st.is_empty() or st.top() != left[i]:
                        return False
                    else:
                        st.pop()
                        break
        if not st.is_empty():
            return False
        return True


class Solution2(object):  # by stack too
    def isValid(self, s):
        st = []
        mapping = {')': '(', ']': '[', '}': '{'}  # 更快，更简洁
        for x in s:
            if x in mapping:
                top = st.pop() if st != [] else '#'
                if mapping[x] != top:
                    return False
            else:
                st.append(x)
        return st == []


class Solution3:  # 作者：h779803，提供了另外一种思路
    def isValid(self, s: str) -> bool:
        s_new = s.replace('()', '').replace('[]', '').replace('{}', '')
        while len(s_new) < len(s):
            s = s_new
            s_new = s.replace('()', '').replace('[]', '').replace('{}', '')
        return not s_new


if __name__ == '__main__':
    S = Solution3()
    print(S.isValid('({})[]'))
'''
错误记录：最后stack应该是empty的，没有判断，特例："("
'''
