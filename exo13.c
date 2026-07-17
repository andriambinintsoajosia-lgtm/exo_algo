#include <stdio.h>

int arrangement_rec(int n, int k) {
    if (k == 0) {
        return 1;
    }
    return n * arrangement_rec(n - 1, k - 1);
}

int main() {
    int n = 5, k = 3; // A(5,3) = 5 * 4 * 3 = 60
    printf("A(%d, %d) = %d\n", n, k, arrangement_rec(n, k));
    return 0;
}