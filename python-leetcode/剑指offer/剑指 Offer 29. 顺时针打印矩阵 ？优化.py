pass
'''
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
'''


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix: return []
        res = []
        go = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        X = len(matrix[0])
        Y = len(matrix)
        vst = [[0 for i in range(X)] for j in range(Y)]
        # print(vst)
        i, j, d = 0, 0, 0
        # Kx = 0  # 多少圈
        for _ in range(X * Y):
            # print(i,j)
            res.append(matrix[i][j])
            vst[i][j] = 1
            ni = i + go[d][0]  # next
            nj = j + go[d][1]
            # print(res, len(res))
            if ni == Y or nj == X or ni < 0 or nj < 0 or vst[ni][nj] == 1:
                d = (d + 1) % 4
                # if d == 0:
                #     K += 1
            i += go[d][0]
            j += go[d][1]

        return res


S = Solution()
print(S.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
print(S.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))
print(S.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]))
