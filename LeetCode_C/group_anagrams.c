#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(const char*)a - *(const char*)b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** result = malloc(strsSize * sizeof(char**));
    char** key = malloc(strsSize * sizeof(char*));
    *returnSize = 0;
    *returnColumnSizes = malloc(strsSize * sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        char* sortedStr = strdup(strs[i]);
        qsort(sortedStr, strlen(sortedStr), sizeof(char), compare);
        
        int found = -1;
        for (int j = 0; j < *returnSize; j++) {
            if (strcmp(sortedStr, key[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            key[*returnSize] = sortedStr;
            result[*returnSize] = malloc(strsSize * sizeof(char*));
            result[*returnSize][0] = strs[i];
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        } else {
            result[found][(*returnColumnSizes)[found]] = strs[i];
            (*returnColumnSizes)[found]++;
            free(sortedStr);
        }
    }

    for (int i = 0; i < *returnSize; i++) {
        free(key[i]);
    }
    free(key);

    return result;
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;
    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            if (j > 0) printf(", ");
            printf("\"%s\"", result[i][j]);
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