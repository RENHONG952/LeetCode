#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = *matrixColSize - 1;
    int* result = malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}

int main() {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    int* matrix[] = {row1, row2, row3};

    int matrixSize = 3;
    int matrixColSize = 3;
    int returnSize;
    int* result = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);

    printf("[[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]]");

    free(result);
    return 0;
}