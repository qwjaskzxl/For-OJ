class Solution:
    def numWays_(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            return (self.numWays_(n - 1) + self.numWays_(n - 2)) % 1000000007

    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        a, b = 1, 2
        for _ in range(n - 1):
            a, b = b, a + b
        return a % 1000000007


S = Solution()
print(S.numWays(0))
print(S.numWays(7))
