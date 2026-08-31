class Solution(object):
    def backtrack(self, row, diagonals, anti_diagonals, cols, state, n, result):
        if row == n:
            result.append(["".join(r) for r in state])
            return

        for col in range(n):
            diag = row - col
            anti_diag = row + col

            if col in cols or diag in diagonals or anti_diag in anti_diagonals:
                continue

            cols.add(col)
            diagonals.add(diag)
            anti_diagonals.add(anti_diag)
            state[row][col] = "Q"

            self.backtrack(row + 1, diagonals, anti_diagonals, cols, state, n, result)

            cols.remove(col)
            diagonals.remove(diag)
            anti_diagonals.remove(anti_diag)
            state[row][col] = "."
        
    def solveNQueens(self, n):
        result = []
        empty_board = [["." for _ in range(n)] for _ in range(n)]
        self.backtrack(0, set(), set(), set(), empty_board, n, result)
        return result

n = 4
sol = Solution()
print(sol.solveNQueens(n))