class Solution_short:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]


class Solution_toStr_2point:
    def isPalindrome(self, x: int) -> bool:
        # 双指针，我这好慢啊
        if x < 0:
            return False
        x = str(x)
        L = len(x)
        for i in range(L):
            if x[i] != x[L - i - 1]:
                return False
        return True


class Solution_reverse_cmp:
    def isPalindrome(self, x: int) -> bool:
        # 直接反转再比较，最慢的
        if x < 0:
            return False
        t, y = x, 0
        while t > 0:
            y = y * 10 + t % 10
            t //= 10
        print(t, x, y)
        return x == y


if __name__ == '__main__':
    S = Solution_reverse_cmp()
    print(S.isPalindrome(121))