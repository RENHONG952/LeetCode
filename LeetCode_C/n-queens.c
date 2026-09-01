#include <stdio.h>
#include <stdlib.h>

void backtrack(char** board, int n, int row, int cols[], int diagonals[], int antiDiagonals[], char**** result, int* capacity, int* returnSize, int** returnColumnSizes) {
    if (row == n) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, sizeof(char**) * (*capacity));
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*capacity));
        }
        (*result)[*returnSize] = malloc(sizeof(char*) * n);
        for (int i = 0; i < n; i++) {
            (*result)[*returnSize][i] = malloc(sizeof(char) * (n + 1));
            for (int j = 0; j < n; j++) {
                (*result)[*returnSize][i][j] = board[i][j];
            }
            (*result)[*returnSize][i][n] = '\0';
        }
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diagonals[row - col + n - 1] || antiDiagonals[row + col]) continue;

        board[row][col] = 'Q';
        cols[col] = 1;
        diagonals[row - col + n - 1] = 1;
        antiDiagonals[row + col] = 1;

        backtrack(board, n, row + 1, cols, diagonals, antiDiagonals, result, capacity, returnSize, returnColumnSizes);

        board[row][col] = '.';
        cols[col] = 0;
        diagonals[row - col + n - 1] = 0;
        antiDiagonals[row + col] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int capacity = 100;
    char*** result = malloc(sizeof(char**) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    *returnSize = 0;

    char** board = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }

    int row = 0;
    int cols[n];
    int diagonals[2 * n - 1];
    int antiDiagonals[2 * n - 1];
    for (int i = 0; i < n; i++) cols[i] = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        diagonals[i] = 0;
        antiDiagonals[i] = 0;
    }

    backtrack(board, n, row, cols, diagonals, antiDiagonals, &result, &capacity, returnSize, returnColumnSizes);

    for (int i = 0; i < n; i++) free(board[i]);
    free(board);

    return result;
}

int main() {
    int n = 6;
    int returnSize;
    int* returnColumnSizes;
    char*** result = solveNQueens(n, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            if (j > 0) printf(", ");
            printf("\"%s\"", result[i][j]);
            free(result[i][j]);
        }
        if (i < returnSize - 1) printf("], ");
        else printf("]");
        free(result[i]);
    }
    printf("]");

    free(result);
    free(returnColumnSizes);
    return 0;
}