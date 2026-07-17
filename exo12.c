#include <stdio.h>

int comb_pascal(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n || k < 0) {
        return 0;
    }
    return comb_pascal(n - 1, k - 1) + comb_pascal(n - 1, k);
}

int main() {
    printf("C(5, 2) [Pascal] = %d\n", comb_pascal(5, 2)); // Affiche 10
    return 0;
}