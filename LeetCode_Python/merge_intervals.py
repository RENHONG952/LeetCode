class Solution(object):
    def merge(self, intervals):
        intervals.sort()
        i = 0
        while i < len(intervals) - 1:
            if intervals[i + 1][0] <= intervals[i][1]:
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1])
                intervals.pop(i + 1)
            else:
                i += 1
        return intervals
    
intervals = [[15,18],[1,3],[2,6],[8,10]]
sol = Solution()
print(sol.merge(intervals))