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


if __name__ == '__main__':
    s = Stack()
    print(s.is_empty())
    s.push(666)
    print(s.top())
    print(s.pop())