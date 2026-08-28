class Solution(object):
    def backtrack(self, nums, path, ans):
        if not nums:
            ans.append(path)
            return
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            self.backtrack(nums[:i] + nums[i + 1:], path + [nums[i]], ans)
    
    def permuteUnique(self, nums):
        ans = []
        nums.sort()
        self.backtrack(nums, [], ans)
        return ans

nums = [1, 1, 2]
sol = Solution()
print(sol.permuteUnique(nums))