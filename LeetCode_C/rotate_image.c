#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixColSize[i]; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i] / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixColSize[i] - 1 - j];
            matrix[i][matrixColSize[i] - 1 - j] = temp;
        }
    }
}

int main(){
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    int* matrix[] = {row0, row1, row2};
    int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
    int matrixColSize[] = {3, 3, 3};
    rotate(matrix, matrixSize, matrixColSize);

    printf("[");
    for (int i = 0; i < matrixSize; i++) {
        printf("[");
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (j > 0) printf(", ");
            printf("%d", matrix[i][j]);
        }
        if (i < matrixSize - 1) printf("], ");
        else printf("]");
    }
    printf("]");
    return 0;
}