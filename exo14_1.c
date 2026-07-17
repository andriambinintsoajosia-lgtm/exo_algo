#include <stdio.h>

void hanoi_rec(int n, char dep, char arr, char inter) {
    if (n == 1) {
        printf("Deplacer disque 1 de %c vers %c\n", dep, arr);
        return;
    }
    hanoi_rec(n - 1, dep, inter, arr);
    printf("Deplacer disque %d de %c vers %c\n", n, dep, arr);
    hanoi_rec(n - 1, inter, arr, dep);
}

int main() {
    int disques = 3;
    printf("Resolution recursive de Hanoi (%d disques) :\n", disques);
    hanoi_rec(disques, 'A', 'C', 'B');
    return 0;
}