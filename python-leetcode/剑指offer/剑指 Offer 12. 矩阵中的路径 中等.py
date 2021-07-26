'''
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
 

提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成
'''


class Solution_666:
    def exist(self, board, word: str) -> bool:
        def dfs(i, j, k):
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            board[i][j] = ''
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k + 1) or dfs(i, j + 1, k + 1) or dfs(i, j - 1, k + 1)
            board[i][j] = word[k]
            return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True
        return False


class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        dir = [[0, 1], [1, 0], [-1, 0], [0, -1]]
        flag = 0

        def dfs(i, j, cnt):
            nonlocal flag
            if cnt == len(word):
                flag = 1
                return True
            if flag:
                return True

            for d in dir:
                x = i + d[0]
                y = j + d[1]
                if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == word[cnt]:
                    board[i][j] = ''  # 相当于以前的：标记map，不让重复走
                    dfs(x, y, cnt + 1)
                    board[i][j] = word[cnt - 1]


        # # 边界条件，但我看他们不需要单独判断啊
        # if board[0][0] == word[0] and len(word) == 1:
        #     return True
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == word[0]:  # 边界条件
                    dfs(i, j, 1)  # 因为初始已经OK了，所以从1开始
                    if flag:
                        return True

        return False


S = Solution()
print(S.exist(board=[["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]],
              word="ABCCED"))
print(S.exist(board=[['A'], ['A']],
              word="AAA"))
print(S.exist(board=[['A']],
              word="A"))
