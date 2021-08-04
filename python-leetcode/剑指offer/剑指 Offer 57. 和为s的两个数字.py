'''
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

限制：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
'''


class Solution(object):  # 没看到是增序的，所以是O(n)
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 1: return nums
        d = {target - nums[0]: nums[0]}
        for x in nums[1:]:
            if x in d:
                return [x, d[x]]
            else:
                d[target - x] = x


class Solution_O1(object):  # 双指针，空间是O(1)
    def twoSum(self, nums, target):
        i, j = 0, len(nums) - 1
        while i < j:
            s = nums[i] + nums[j]
            if s > target:
                j -= 1
            elif s < target:
                i += 1
            else:
                return nums[i], nums[j]
        return []


class Solution_bi(object):  # 先二分找到比较好的初始 右指针
    def bi_search(self, nums, target):
        a, b = 0, len(nums) - 1
        while a < b:
            mid = (b + a) // 2
            if nums[mid] > target:  # 这里是>，最后 a 会到mid的右边，所以不会错过。无论如何，a都会到mid的右边
                b = mid - 1
            else:  # 不管=还是<，都让a到右边去
                a = mid + 1
        return a

    def twoSum(self, nums, target):
        i, j = 0, self.bi_search(nums, target)
        while i < j:
            s = nums[i] + nums[j]
            if s > target:
                j -= 1
            elif s < target:
                i += 1
            else:
                return nums[i], nums[j]
        return []
