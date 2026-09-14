#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc((intervalsSize + 1) * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));
    bool inserted = false;
    int i = 0;

    while (i < intervalsSize) {
        if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0]) {
            newInterval[0] = (intervals[i][0] > newInterval[0]) ? newInterval[0] : intervals[i][0];
            newInterval[1] = (intervals[i][1] < newInterval[1]) ? newInterval[1] : intervals[i][1];
        } else {
            if (intervals[i][1] < newInterval[0]) {
                ans[*returnSize] = malloc(2 * sizeof(int));
                ans[*returnSize][0] = intervals[i][0];
                ans[*returnSize][1] = intervals[i][1];
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            } else {
                inserted = true;
                ans[*returnSize] = malloc(2 * sizeof(int));
                ans[*returnSize][0] = newInterval[0];
                ans[*returnSize][1] = newInterval[1];
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;

                for (int j = i; j < intervalsSize; j++) {
                    ans[*returnSize] = malloc(2 * sizeof(int));
                    ans[*returnSize][0] = intervals[j][0];
                    ans[*returnSize][1] = intervals[j][1];
                    (*returnColumnSizes)[*returnSize] = 2;
                    (*returnSize)++;
                }
                break;
            }
        }
        i ++;
    }
    if (!inserted) {
        ans[*returnSize] = malloc(2 * sizeof(int));
        ans[*returnSize][0] = newInterval[0];
        ans[*returnSize][1] = newInterval[1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return ans;
}

int main() {
    int inter_A[] = {1, 3};
    int inter_B[] = {6, 9};
    int *intervals[] = {inter_A, inter_B};
    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);
    int intervalsColSize[] = {2, 2};
    int newInterval[] = {2,5};
    int newIntervalSize = sizeof(newInterval) / sizeof(newInterval[0]);
    int returnSize;
    int* returnColumnSizes;
    int** ans = insert(intervals, intervalsSize, intervalsColSize, newInterval, newIntervalSize, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("[%d, %d]", ans[i][0], ans[i][1]);
    }

    printf("]");

    for (int i = 0; i < returnSize; i++) {
        free(ans[i]);
    }

    free(ans);
    free(returnColumnSizes);
    return 0;
}