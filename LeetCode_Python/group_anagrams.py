class Solution(object):
    def groupAnagrams(self, strs):
        anagrams = {}
        
        for i in strs:
            sorted_str = ''.join(sorted(i))
            if sorted_str in anagrams:
                anagrams[sorted_str].append(i)
            else:
                anagrams[sorted_str] = [i]

        return list(anagrams.values())
    
strs = ["eat","tea","tan","ate","nat","bat"]
sol = Solution()
ans = sol.groupAnagrams(strs)
print(ans)