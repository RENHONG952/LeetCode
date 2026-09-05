class Solution(object):
    def backtrack(self, total, row, cols, diag1, diag2, n):
        if row == n:
            total += 1
            return total

        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue

            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)

            total = self.backtrack(total, row + 1, cols, diag1, diag2, n)

            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)

        return total

    def totalNQueens(self, n):
        total = self.backtrack(0, 0, set(), set(), set(), n)
        return total

n = 5
sol = Solution()
print(sol.totalNQueens(n))