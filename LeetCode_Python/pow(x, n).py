class Solution(object):
    def myPow(self, x, n):
        if n == 0 : return 1

        if n < 0:
            return 1 / self.myPow(x, -n)
        elif n % 2 == 0:
            return self.myPow(x * x, n // 2)
        else:
            return x * self.myPow(x * x, n // 2)

x = 2.10000
n = 3
sol = Solution()
result = sol.myPow(x, n)
print(f"{result:.5f}")