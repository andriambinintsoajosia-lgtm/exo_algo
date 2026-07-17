#include <stdio.h>

// Version recursive
void binaire_rec(int n) {
    if (n > 1) {
        binaire_rec(n / 2);
    }
    printf("%d", n % 2);
}

// Version iterative utilisant un tableau (pile) pour inverser l'affichage
void binaire_iter(int n) {
    int bits[32];
    int i = 0;
    if (n == 0) {
        printf("0");
        return;
    }
    while (n > 0) {
        bits[i++] = n % 2;
        n /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
}

int main() {
    int n = 13; // Binaire attendu : 1101
    printf("Binaire Rec de %d : ", n);
    binaire_rec(n);
    printf("\nBinaire Iter de %d : ", n);
    binaire_iter(n);
    printf("\n");
    return 0;
}