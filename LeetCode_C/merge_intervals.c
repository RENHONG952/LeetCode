#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int** merged = malloc(intervalsSize * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));
    
    int i = 0;
    while (i < intervalsSize) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        
        while (i < intervalsSize - 1 && intervals[i + 1][0] <= end) {
            end = (end > intervals[i + 1][1]) ? end : intervals[i + 1][1];
            i++;
        }
        
        merged[*returnSize] = malloc(2 * sizeof(int));
        merged[*returnSize][0] = start;
        merged[*returnSize][1] = end;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        
        i++;
    }

    return merged;
}

int main(){
    int interval_A[] = {8, 10};
    int interval_C[] = {1, 3};
    int interval_B[] = {2, 6};
    int interval_D[] = {15, 18};
    int* intervals[] = {interval_A, interval_B, interval_C, interval_D};

    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);
    int intervalsColSize[] = {2, 2, 2, 2};
    int returnSize;
    int* returnColumnSizes;

    int** reuslt = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("[%d, %d]", reuslt[i][0], reuslt[i][1]);
    }

    printf("]");

    for (int i = 0; i < returnSize; i++) {
        free(reuslt[i]);
    }

    free(reuslt);
    free(returnColumnSizes);
    return 0;
}