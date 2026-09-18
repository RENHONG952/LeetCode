#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));
    int** ans = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) ans[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) (*returnColumnSizes)[i] = n;

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans[top][i] = num;
            num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            ans[i][right] = num;
            num++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[bottom][i] = num;
                num++;
            }
        }
        bottom--;

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[i][left] = num;
                num++;
            }
        }
        left++;
    }

    return ans;
}

int main() {
    int n = 3;
    int returnSize;
    int* returnColumnSizes;
    int** ans = generateMatrix(n, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", ans[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]");

        if (i < returnSize - 1) printf(", ");
        free(ans[i]);
    }
    printf("]");
    
    free(ans);
    free(returnColumnSizes);
}