'''
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000
1 <= nums[i] <= 10000
'''


class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) <= 1: return nums
        a, b = 0, len(nums)-1
        while a < b:
            if nums[a] % 2 == 1:
                a += 1
                continue
            if nums[b] % 2 == 0:
                b -= 1
                continue

            nums[a], nums[b] = nums[b], nums[a]
        return nums


class Solution_(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a,b=[],[]
        for x in nums:
            if x%2==1:
                a.append(x)
            else:
                b.append()
        return a+b