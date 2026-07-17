#include <stdio.h>

long long factorielle_iterative(int n) {
    long long res = 1;
    int i = 2;
    while (i <= n) {
        res *= i;
        i++;
    }
    return res;
}

int main() {
    int n = 6;
    printf("%d! = %lld\n", n, factorielle_iterative(n)); // Affiche 720
    return 0;
}