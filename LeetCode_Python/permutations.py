class Solution(object):
    def permute(self, nums):
        result = []
        self.backtrack(nums, [], result)
        return result

    def backtrack(self, nums, path, result):
        if not nums:
            result.append(path)
            return
        
        for i in range(len(nums)):
            self.backtrack(nums[:i] + nums[i+1:], path + [nums[i]], result)

num = [1, 2, 3]
sol = Solution()
result = sol.permute(num)
print(result)