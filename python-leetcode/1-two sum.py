#two sum I
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # O(n*(n-1)/2):TLE
        # L = len(nums)
        # # nums = nums.sort()
        # print(nums)
        # for i in range(L):
        #     for j in range(i+1, L):
        #         if nums[i]+nums[j]==target:
        #             return [i,j]
        hash_nums = {}
        for i, x in enumerate(nums):  
            try:
                hash_nums[x].append(i) #可能有重复
            except:
                hash_nums[x] = [i]
        # print(hash_nums)
        for x in nums:
            y = target - x
            try:
                if len(hash_nums[y]) == 2 and x==y:
                    return hash_nums[y]
                elif x!=y: #执行到这里说明一定有len(hash)==1，不然就会except了
                    return [hash_nums[x][0], hash_nums[y][0]]
            except:
                continue
				
#two sum II
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 方法1:hash, O(n)
        # hash_nums = {}
        # for i,x in enumerate(numbers):
        #     try:
        #         hash_nums[x].append(i+1)
        #     except:
        #         hash_nums[x] = [i+1]
        # # print(hash_nums)
        # for x in numbers:
        #     y = target - x
        #     try:
        #         if len(hash_nums[x])==2 and x==y:
        #             return hash_nums[x]
        #         elif x!=y:
        #             return [hash_nums[x][0], hash_nums[y][0]]
        #     except:
        #         continue

        # 方法2:two point, O(n)
        i, j = 0, len(numbers)-1
        while 1:
            if numbers[i] + numbers[j] > target:
                j-=1
            elif numbers[i] + numbers[j] < target:
                i+=1
            else:
                return [i+1, j+1]
        
        # 方法3:二分, O(logn)----WRONG!!!
        # i, j = 0, len(numbers)-1
        # k = (i+j)//2
        # while i<j:
        #     # print(i,k,j)
        #     if 2 * numbers[k] < target:

        #         i = k-1 if k-1>-1 else 0
        #         k = (i+j)//2+1 if (i+j)//2+1<len(numbers) else len(numbers)-1
        
        #     elif 2 * numbers[k] > target:
        #         j = k+1 if k+1<len(numbers) else len(numbers)-1
        #         k = (i+j)//2

        #     else: #下面顺序不能颠倒，为防止越界
        #         if numbers[k]+numbers[k]==target:
        #             return [k+1,k+1]
        #         if numbers[k-1]+numbers[k]==target:
        #             return [k,k+1]
        #         if numbers[k]+numbers[k+1]==target:
        #             return [k+1,k+2]