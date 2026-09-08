class Solution(object):
    def canJump(self, nums):
        max_location = len(nums) - 1
        max_reach = 0
        for i in range(len(nums)):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + nums[i])
            if max_reach >= max_location:
                return True

nums = [2,3,1,1,4]
sol = Solution()
print(sol.canJump(nums))