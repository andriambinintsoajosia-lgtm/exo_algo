#include <stdio.h>
#include <stdbool.h>

// Declarations initiales pour permettre l'appel mutuel
bool est_paire(unsigned int n);
bool est_impaire(unsigned int n);

bool est_paire(unsigned int n) {
    if (n == 0) return true;
    return est_impaire(n - 1);
}

bool est_impaire(unsigned int n) {
    if (n == 0) return false;
    return est_paire(n - 1);
}

int main() {
    unsigned int n1 = 14, n2 = 7;
    printf("%u est pair ? %s\n", n1, est_paire(n1) ? "Oui" : "Non");
    printf("%u est impair ? %s\n", n2, est_impaire(n2) ? "Oui" : "Non");
    return 0;
}