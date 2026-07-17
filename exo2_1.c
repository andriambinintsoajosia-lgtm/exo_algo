#include <stdio.h>

long long puissance_lineaire_iterative(long long a, int n) {
    long long resultat = 1;
    int i = 0;
    while (i < n) {
        resultat *= a;
        i++;
    }
    return resultat;
}

int main() {
    long long a = 3;
    int n = 4;
    printf("%lld ^ %d = %lld\n", a, n, puissance_lineaire_iterative(a, n));
    return 0;
}