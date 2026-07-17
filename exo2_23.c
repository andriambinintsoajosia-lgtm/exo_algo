#include <stdio.h>

long long puissance_rapide_iterative(long long a, int n) {
    long long resultat = 1;
    while (n > 0) {
        if (n % 2 == 1) { // Si n est impair
            resultat *= a;
        }
        a *= a;  // On met la base au carré
        n /= 2;  // Division entière de l'exposant par 2
    }
    return resultat;
}

int main() {
    long long a = 2;
    int n = 10;
    printf("%lld^%d = %lld\n", a, n, puissance_rapide_iterative(a, n));
    return 0;
}