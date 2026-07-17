#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int n;
    char dep, arr, inter;
    int etape; // Etape du traitement pour la simulation d'appels (0, 1, 2)
} Commande;

Commande pile[100];
int sommet = -1;

void empiler(int n, char dep, char arr, char inter, int etape) {
    sommet++;
    pile[sommet].n = n;
    pile[sommet].dep = dep;
    pile[sommet].arr = arr;
    pile[sommet].inter = inter;
    pile[sommet].etape = etape;
}

Commande depiler() {
    return pile[sommet--];
}

bool pileVide() {
    return sommet == -1;
}

void hanoi_iteratif(int total_disques) {
    empiler(total_disques, 'A', 'C', 'B', 0);

    while (!pileVide()) {
        Commande cmd = depiler();

        if (cmd.n == 1) {
            printf("Deplacer disque 1 de %c vers %c\n", cmd.dep, cmd.arr);
            continue;
        }

        if (cmd.etape == 0) {
            // Re-empiler la commande courante modifiee a l'etape 1
            empiler(cmd.n, cmd.dep, cmd.arr, cmd.inter, 1);
            // Empiler le sous-probleme 1
            empiler(cmd.n - 1, cmd.dep, cmd.inter, cmd.arr, 0);
        } else if (cmd.etape == 1) {
            // Action centrale
            printf("Deplacer disque %d de %c vers %c\n", cmd.n, cmd.dep, cmd.arr);
            // Empiler le sous-probleme 2
            empiler(cmd.n - 1, cmd.inter, cmd.arr, cmd.dep, 0);
        }
    }
}

int main() {
    int disques = 3;
    printf("Resolution iterative (Pile) de Hanoi (%d disques) :\n", disques);
    hanoi_iteratif(disques);
    return 0;
}