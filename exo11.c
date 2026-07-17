#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 8; // Suite : 0, 1, 1, 2, 3, 5, 8, 13, 21...
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n)); // Affiche 21
    return 0;
}