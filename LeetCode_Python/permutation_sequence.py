class Solution(object):
    def factorial(self, number):
        total = 1
        for i in range(number, 0, -1): total *= i 
        return total
    
    def getPermutation(self, n, k):
        numbers = list(range(1, n + 1))
        result = []

        for _ in range(n):
            num = self.factorial(len(numbers) - 1)
            index = (k - 1) // num
            result.append(numbers.pop(index))
            k = k - index * num

        return ''.join(map(str, result))
n = 3
k = 3
sol = Solution()
ans = sol.getPermutation(n, k)
print(ans)