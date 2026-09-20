#include <stdlib.h>
#include <stdio.h>

int factorial(int number) {
    int total = 1;
    for (int i = number; i >= 2; i--) total *= i;
    return total;
}

char* getPermutation(int n, int k) {
    int numbers[n];
    int numbersSize = n;
    for (int i = 0; i < n; i++) numbers[i] = i + 1;
    char* ans = malloc(n + 1);

    for (int i = 0; i < n; i++) {
        int num = factorial(numbersSize - 1);
        int index = (k - 1) / num;
        ans[i] = numbers[index] + '0';
        for (int j = index; j < numbersSize - 1; j ++) numbers[j] = numbers[j + 1];
        numbersSize--;
        k = k - index * num;
    }

    ans[n] = '\0';
    return ans;
}

int main() {
    int n = 3;
    int k = 3;
    char* ans = getPermutation(n, k);
    printf("%s", ans);
    free(ans);
}