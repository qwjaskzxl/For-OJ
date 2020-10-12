class Solution_my:
    def removeDuplicates(self, nums: list) -> int:
        i = 1
        while 1:
            if len(nums) == i or len(nums) <= 1:
                break
            if nums[i] == nums[i - 1]:
                nums.pop(i)
            else:
                i += 1
        return len(nums)


'''
注意特判数组为0或1的情况；但下面官方的双指针方式就可以完美处理，而且不用每次pop，也是O(n)，但速度更快。
反思：双指针就是两个point以不用的方向/跨度从而优化程序，这题我刚开始就局限在想返回一个全新的list，从而return len(list)，但其实只要保证前k位是新list就可以了
'''


class Solution:
    # 双指针
    def removeDuplicates(self, nums: list) -> int:
        j, x = 0, ''
        for i in range(len(nums)):
            if nums[i] != x and i >= j:  # 后面这个可以防止一个完全无重复的数组也被一次次赋值，速度从超过5%到80%
                nums[j] = nums[i]
                x = nums[i]
                j += 1
        return j


if __name__ == '__main__':
    S = Solution()
    nums = [1, 1, 2]
    L = S.removeDuplicates(nums)
    print(nums[:L])
