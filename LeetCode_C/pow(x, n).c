#include <stdio.h>

double myPow(double x, int n) {
    if (n == 0) return 1;

    if (n < 0) {
        return 1 / myPow(x, -n);
    } else if (n % 2 == 0) {
        return myPow(x * x , n / 2);
    } else {
        return x * myPow(x * x, n / 2);
    }
}

int main() {
    double x = 2.00000;
    int n = 10;
    double result = myPow(x, n);
    printf("%.5f", result);
    return 0;
}