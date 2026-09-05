#include <stdio.h>

void backtrack(int n, int row, int cols[], int diagonals[], int antiDiagonals[], int *totalSolutions) {
    if (row == n) {
        (*totalSolutions)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diagonals[row - col + n - 1] || antiDiagonals[row + col]) {
            continue;
        }

        cols[col] = 1;
        diagonals[row - col + n - 1] = 1;
        antiDiagonals[row + col] = 1;

        backtrack(n, row + 1, cols, diagonals, antiDiagonals, totalSolutions);
       
        cols[col] = 0;
        diagonals[row - col + n - 1] = 0;
        antiDiagonals[row + col] = 0;
    }
}

int totalNQueens(int n) {
    int cols[n];
    int diagonals[2 * n - 1];
    int antiDiagonals[2 * n - 1];
    for (int i = 0; i < n; i++) cols[i] = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        diagonals[i] = 0;
        antiDiagonals[i] = 0;
    }

    int totalSolutions = 0;
    backtrack(n, 0, cols, diagonals, antiDiagonals, &totalSolutions);
    return totalSolutions;
}

int main() {
    int n = 5;
    int result = totalNQueens(n);
    printf("%d", result);
    return 0;
}