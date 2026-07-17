#include <stdio.h>

// Fonction recursive interne
int nb_chiffres_rec(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + nb_chiffres_rec(n / 10);
}

// Fonction finale securisee (gere l'entree 0)
int nb_chiffres_rec_final(int n) {
    if (n == 0) return 1;
    if (n < 0) n = -n; // Prise en charge des nombres negatifs
    return nb_chiffres_rec(n);
}

// Version iterative
int nb_chiffres_iter(int n) {
    int c = 0;
    if (n == 0) return 1;
    if (n < 0) n = -n;
    while (n > 0) {
        c++;
        n /= 10;
    }
    return c;
}

int main() {
    int n1 = 0;
    int n2 = 45281;
    printf("[Rec] Chiffres dans %d : %d\n", n1, nb_chiffres_rec_final(n1));
    printf("[Rec] Chiffres dans %d : %d\n", n2, nb_chiffres_rec_final(n2));
    printf("[Iter] Chiffres dans %d : %d\n", n2, nb_chiffres_iter(n2));
    return 0;
}