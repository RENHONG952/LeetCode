class Solution(object):
    def lengthOfLastWord(self, s):
        final_word = []

        for i in range(len(s) - 1, -1, -1):
            if s[i] != " " : final_word.append(s[i])
            else:
                if len(final_word) != 0 : break

        return len(final_word)
    
s = "Hello World"
sol = Solution()
print(sol.lengthOfLastWord(s))