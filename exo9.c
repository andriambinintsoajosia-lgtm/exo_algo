#include <stdio.h>

int comb_rec(int n, int k, int i, int res) {
    if (i > k) {
        return res;
    }
    return comb_rec(n, k, i + 1, res * (n - k + i) / i);
}

int comb(int n, int k) {
    if (k > n - k) {
        k = n - k; // Propriete C(n, k) = C(n, n-k) pour optimiser
    }
    return comb_rec(n, k, 1, 1);
}

int main() {
    printf("C(5, 2) = %d\n", comb(5, 2)); // Affiche 10
    return 0;
}