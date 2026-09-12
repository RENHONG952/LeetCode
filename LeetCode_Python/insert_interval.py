class Solution(object):
    def insert(self, intervals, newInterval):
        i = 0
        result = []
        inserted = False

        while i < len(intervals):
            if intervals[i][1] >= newInterval[0] and intervals[i][0] <= newInterval[1]:
                newInterval[0] = min(intervals[i][0], newInterval[0])
                newInterval[1] = max(intervals[i][1], newInterval[1])
            else:
                if intervals[i][1] < newInterval[0]:
                    result.append(intervals[i])
                else:
                    inserted = True
                    result.append(newInterval)
                    result.extend(intervals[i:])
                    break
            i += 1

        if not inserted:
            result.append(newInterval)
        return result
            
intervals = [[1,3],[6,9]]
newInterval = [2,5]
sol = Solution()
print(sol.insert(intervals, newInterval))